#pragma once

// the WindowProc function prototype
//LRESULT CALLBACK WindowProc(HWND hWnd,
	//UINT message,
	//WPARAM wParam,
	//LPARAM lParam);








// the entry point for any Windows program
//int WINAPI WinMain(HINSTANCE hInstance, // abrbreviation for "handle to an instance". It is a 32-bit integer (instance is acopy of an application)
	//HINSTANCE hPrevInstance,  // "handle to the previous instance" it detects any running copies (obsolete
	//LPSTR lpCmdLine,  // long pointer to a strng that contains the command line calling existence to the application
	//int nCmdShow) {  // indicates how the windows is to appear when created
	// the handle for the window, filled by a function
	//HWND hWnd;

	/*
	 * WNDCLASSEX: This is a struct that contains the information for the window class.
	 * It call a struct. By the way, the 'EX' is there to idnciate that this is the extended version of the struct WNDCLASS
	 * which is essentially the same, but without a couple extra things. The same goes for th CreateWindowEx() and RegisterClassEx()
	*/
	//WNDCLASSEX wc; // WNDCLASSEX is the struct to holds information to assamble window class


	/*
	 * ZeroMemory(&wc, sizeof(WNDCLASSEX)):
	 * ZeroMemory is a function that initializes an entire block of memory to NULL. The address provided in the first parameter sets where the block is to start.
	 * @arg &wc, is the start address
	 * @arg sizeof(WNDCLASSEX), indicates how long the block is
	*/
	//ZeroMemory(&wc, sizeof(WNDCLASSEX));

	/*
	 * The next parameters are the variables of the WNDCLASSEX structure
	*/
	//wc.cbSize = sizeof(WNDCLASSEX);  // This is the size of the structure
	//wc.style = CS_HREDRAW | CS_VREDRAW;  // In this member, we store the style of the window. 
	//wc.lpfnWndProc = WindowProc;  // This value tell the window class
	//wc.hInstance = hInstance;  // It is a handle to a copy of our application (is the value of winMain)
	//wc.hCursor = LoadCursor(NULL, IDC_ARROW);  //This member stores the default mouse image for the window class. It has two parameters, the first is the hInstance of the apllication that stores the pinter graphic, the second one is a value that contains the default mouse pointer
	//wc.hbrBackground = (HBRUSH)COLOR_WINDOW;  // This member contains the 'brush' that will be used to color the background of our window. COLOR_WINDOW indicates a brush that paints the window white
	//wc.lpszClassName = L"WindowClass1";  // This is the name of the window class we are building. The 'L' that appears before the string, simply tells the compiler that this string should be made of 16 bit unicode char, rather tahn the usar 8 bit ANSI char


	// register the window class
	//RegisterClassEx(&wc);  // This function finally registers the window class. We fill its single parameter with the address of the struct we put together and Windows takes care of the rest


	/*
	 * RECT wr = {0, 0, 500,400};
	 * This is a simple statement. We create a rect (which i have named 'wr'for window rect), and initialize it with the size of the desired client area.
	 *
	 * AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
	 * After the RECT is initialized, we call the AdjustWindowRect() function. We fill it with the address and RECT, the window style, and FALSE to indicate there is no menu.
	 *
	 * wr.right -wr.left,
	 * wr.bottom - wr.top
	 * When AdjustWindowRect() is called, the window width will be difference between the right and the left, and the height will be the difference btween the bottom and the top
	 *
	*/

	//RECT wr = { 0,0, 500, 400 };  // set the size, but not the position
	//AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);  // adjust the size

	/*
	 * Prototype of the CreateWindowEx function:
	 * HWND CreateWindowEx(DWORD dwExStyle,
	 *              LPCTSTR lpClassName,
	 *              LPCTSTR lpWindowName,
	 *              DWORD dwStyle,
	 *              int x,
	 *              int y,
	 *              int nWidth,
	 *              int nHeight,
	 *              HWND hWndParent,
	 *              HMENU hMenu,
	 *              HINSTANCE hInstance,
	 *              LPVOID lpParam);
	 *
	 * @arg DWORD dwExStyle, This is parameter was added when RegisterClass() was upgraded to the extended RegisterClassEx(). It is an extension of the fourth parameter, dwStyle, and simply adds more oprtions for the window style.
	 * @arg LPCTSTR lpClassName, This is the name of the class our window will use.
	 * @arg LPCTSTR lpWindowName, this is the name of the window, and it will be displayed in the window's tittle bar.
	 * @arg DWORD dwStyle, This is where we can define all kinds of options for the window.
	 * @arg int x, x-axis position of the screen
	 * @arg int y, y-axis position of the screen
	 * @arg int nWidth, here we set ht initial width of the window
	 * @arg int nHeight, here we set the initial height of the window
	 * @arg HWND hWndParent, this is a parameter which tells windows what parent window created the window we are now making. A parent window is awindow that contains other windows. An example microsoft word, which can open multiple documents in the same window, consist of a parent window with multiple 'child' windows.
	 * @arg HMENU hMenu, This is a handle to a menu bar. When it doesnt have menu put NULL.
	 * @arg HINSTANCE hInstance, This is the handle to the instance. Set it to hInstance.
	 * @arg LPVOID lpParam, This is a parameter we would use if we were creating a multiple windows. Because we are not, we will just keep it simple and leave it as NULL.
	 * Return Value, The return value of this function is the handle windows will assign this new window. store ir directly into our hWnd variable,
	*/


	// create the window and use the result as the handle
	//hWnd = CreateWindowEx(NULL,
		//L"WindowClass1",    // name of the window class
		//L"Our First Windowed Program",   // title of the window
		//WS_OVERLAPPEDWINDOW,    // window style
		//300,    // x-position of the window
		//300,    // y-position of the window
		//wr.right - wr.left,    // width of the window
		//wr.bottom - wr.top,    // height of the window
		//NULL,    // we have no parent window, NULL
		//NULL,    // we aren't using menus, NULL
		//hInstance,    // application handle
		//NULL);    // used with multiple windows, NULL

/*
 * Show the window. It is to show the visible window it has two parameters.
 * @arg HWND hWnd, This is simply the handle to the window we just created. We put the value Windows gave back to us.
 * @arg int nCmdShow, we put the last parameter of WinMain(), In a game it really won't matter. Because the window will be fullscreen
*/
//ShowWindow(hWnd, nCmdShow);

/*
* Main Loop
* MSG msg, is a struct wich contains all data regarding a single event message. If i want to access directly its contents then:
* MEMBERS                                    DESCRIPTIONS
* HWND hWnd					Contains the handle of the window which recieved the message.
* UINT message				Contains the identifier of the message sent.
* WPARAM wParam				Contains additional information about the message. The exact meaning depends on what message was sent.
* LPARAM lParam				Identical to WPARAM, and simply contains more information.
* DWORD time				Contains the exact time at which the message was posted in the event queue.
* POINT pt					Contains the exact mouse position, in screen coordinates, when the message was posted.
*/

// this struct holds Windows event messages
//MSG msg;

/*
 * GetMessage() is the function that gets any message out of the message queue and into our msg struct. It alwas returns TUE, except for when the program is about to exit, in that case returns FALSE. So the while() is only broken when the program is completely finished.
 * GetMessage() function has four parameters and bool return
 * @arg LPMSG lpMsg, This parameter is a pointer to a message struct. So just put an address of a struct in there.
 * @arg HWND hWnd, This is the handle to the window the message should come from. Null means get the next message for any of our windows.
 * @arg UINT wMsgFilterMin, UINT wMsgFilterMax, These parameters can be used to limit the types of message to retrieve off the message queue.
 * Example: using WM_KEYFIRST in the wMsgFilterMin and using WM_KEYLAST limit the message type to keyboard messages.
 * If you fill each value with '0', then getMessage() assumes that you want to gather any message, no matter its value.

*/

// wait for the next message in the queue, store the result in 'msg'
//while (GetMessage(&msg, NULL, 0, 0)) {
//	// translate keystroke messages into the right format
//	TranslateMessage(&msg); // TranslateMessage() is a function that translates certain key-presses into the proper format. 
//
//	// send the message to the WindowProc function
//	DispatchMessage(&msg);  // DispatchMessage() basically does what it says. it dispatches the message. it dispatches it to our WindowProc() function.
//}

// return this part of the WM_QUIT message to Windows
//return msg.wParam;

// this struct holds Windows event messages
	//MSG msg = { 0 };

	// Enter the infinite message loop
	//while (TRUE)
	//{
		// Check to see if any messages are waiting in the queue
		//if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		//{
			// translate keystroke messages into the right format
			//TranslateMessage(&msg);

			// send the message to the WindowProc function
			//DispatchMessage(&msg);

			// check to see if it's time to quit
			//if (msg.message == WM_QUIT)
				//break;
		//}
		//else
		//{
			// Run game code here
			// ...
			// ...
		//}

//}

/*
 * WindowProc()
 * When this function is called, four pieces of information form the MSG struct get passed in
 *
*/
// this is the main message handler for the program
//LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
	// sort through and find what code to run for the message given
	//switch (message)
	//{
		// this message is read when the window is closed
	//case WM_DESTROY:
	//{
		// close the application entirely
		//PostQuitMessage(0);
		//return 0;
	//} break;
	//}

	// Handle any messages the switch statement didn't
	//return DefWindowProc(hWnd, message, wParam, lParam);
//}

/*


#define ERROR_CHECK(ret)										\
	if (ret != S_OK) {											\
		std::stringstream ss;									\
		ss << "failed" #ret "" << std::hex << std::endl;		\
		throw std::runtime_error(ss.str().c_str());				\
	}

void moveKinectAngle(long &angle);

int WINAPI WinMain(HINSTANCE hInstance, // abrbreviation for "handle to an instance". It is a 32-bit integer (instance is acopy of an application)
	HINSTANCE hPrevInstance,  // "handle to the previous instance" it detects any running copies (obsolete
	LPSTR lpCmdLine,  // long pointer to a strng that contains the command line calling existence to the application
	int nCmdShow);  // indicates how the windows is to appear when created


int main()
{
	NuiInitialize(NUI_INITIALIZE_FLAG_USES_COLOR |
				  NUI_INITIALIZE_FLAG_USES_DEPTH_AND_PLAYER_INDEX |
				  NUI_INITIALIZE_FLAG_USES_SKELETON |
				  NUI_INITIALIZE_FLAG_USES_AUDIO |
				  NUI_INITIALIZE_FLAG_USES_DEPTH |
				  NUI_INITIALIZE_FLAG_USES_HIGH_QUALITY_COLOR);
	long _angle;
	while (true)  {
		std::cout << "Input your angle!\n";
		std::cin >> _angle;
		moveKinectAngle(_angle);
	}
}


void moveKinectAngle(long &angle) {
	NuiCameraElevationSetAngle(angle);
	Sleep(1000);
}
*/
/*
// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd) {
	// create a "Hello World" message box using MessageBox()
/*
 * This function is to show a messagebox of windows
 *
 * @arg HWND hWnd, is a handle to a window handles are integers wich identify an object. Becauso windows doesnt exist put NULL
 * @arg LPCTSTR lptext, this is a pointer to a 16 bit string, that contains the text of the message box
 * @arg LPCTSTR lpcaption, this is a pointer to a 16 bit string that contains the text of the tittle bar
 * @arg UINT utype, This parameter determines what the style of the message box is.
*/
/*
	MessageBox(NULL,
		L"Hello World!",  // Text inside the messagebox
		L"Just another Hello World program!", // is the tittle
		MB_ICONEXCLAMATION | MB_OKCANCEL);
	// return 0 to Windows
	return 0;
}*/