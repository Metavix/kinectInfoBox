#include "PrincipalWindow.h"

PrincipalWindow::PrincipalWindow(HINSTANCE hInstance, wchar_t* lpCmdLine)
	:
	wstringArgs(lpCmdLine),
	hInstance(hInstance) 
{
	/*
	 * WNDCLASSEX: This is a struct that contains the information for the window class.
	 * It call a struct. By the way, the 'EX' is there to idnciate that this is the extended version of the struct WNDCLASS
	 * which is essentially the same, but without a couple extra things. The same goes for th CreateWindowEx() and RegisterClassEx()
	*/
	WNDCLASSEX wc;
	/*
	 * ZeroMemory(&wc, sizeof(WNDCLASSEX)):
	 * ZeroMemory is a function that initializes an entire block of memory to NULL. The address provided in the first parameter sets where the block is to start.
	 * @arg &wc, is the start address
	 * @arg sizeof(WNDCLASSEX), indicates how long the block is
	*/
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;  // In this member, we store the style of the window.
	wc.lpfnWndProc = _HandleMsgSetup;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = L"WindowClass1";
	// Register de window class
	RegisterClassEx(&wc);
	// calculate the size of the client area
	RECT wr = { 0, 0, 500, 400 };    // set the size, but not the position
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);    // adjust the size

	// create the window and use the result as the handle
	hWnd = CreateWindowEx(NULL,
		L"WindowClass1",    // name of the window class
		L"Our First Windowed Program",    // title of the window
		WS_OVERLAPPEDWINDOW,    // window style
		300,    // x-position of the window
		300,    // y-position of the window
		wr.right - wr.left,    // width of the window
		wr.bottom - wr.top,    // height of the window
		NULL,    // we have no parent window, NULL
		NULL,    // we aren't using menus, NULL
		hInstance,    // application handle
		NULL);    // used with multiple windows, NULL


	// display the window on the screen
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
}
PrincipalWindow::~PrincipalWindow()
{
	UnregisterClass(wndClassName, hInstance);
}
bool PrincipalWindow::ProcessMessage()
{
	MSG msg = {0};
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
	{
		// translate keystroke messages into the right format
		TranslateMessage(&msg);
		// send the message to the WindowProc function
		DispatchMessage(&msg);
		if (msg.message == WM_QUIT)
			return false;
	}
	return true;
}

LRESULT WINAPI PrincipalWindow::_HandleMsgSetup(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// This is neccesary you need a way to track the state of your application from one function call to the next
	// Refer to : https://docs.microsoft.com/es-es/windows/win32/learnwin32/managing-application-state-?redirectedfrom=MSDN
	if (message == WM_NCCREATE)
	{
		// extract ptr to window class from creation data
		// MTVX: First, get the CREAESTRUCT structure by casting the lParam parameter
		const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
		// MTVX: The lpCreateParams member of the CREATESTRUCT structure is the original void pointer that you
		// specified in CreateWindowEx. Get a pointer to your own data structure by casting lpCreateParams
		PrincipalWindow* const pWnd = reinterpret_cast<PrincipalWindow*>(pCreate->lpCreateParams);
		// sanity check
		//assert(pWnd != nullptr);
		// set WinAPI-managed user data to store ptr to window class
		// MTVX: Next, call the setWindowLongPtr function and pass in the pointer to your data structure
		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
		// set message proc to normal (non-setup) handler now that setup is finished
		SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&PrincipalWindow::_HandleMsgThunk));
		// forward message to window class handler
		return pWnd->HandleMsg(hWnd, message, wParam, lParam);
	}
	// if we get a message before the WM_NCCREATE message, handle with default handler
	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT WINAPI PrincipalWindow::_HandleMsgThunk(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// retrieve ptr to window class
	PrincipalWindow* const pWnd = reinterpret_cast<PrincipalWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	// forward message to window class handler
	return pWnd->HandleMsg(hWnd, message, wParam, lParam);
}

LRESULT PrincipalWindow::HandleMsg(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// sort through and find what code to run for the message given
	switch (message)
	{
		// this message is read when the window is closed
	case WM_DESTROY:
	{
		// close the application entirely
		PostQuitMessage(0);
		return 0;
	} break;
	}

	// Handle any messages the switch statement didn't
	return DefWindowProc(hWnd, message, wParam, lParam);
}
