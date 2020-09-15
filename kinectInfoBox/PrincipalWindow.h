#pragma once
#include "general.h"
#include <string>

class PrincipalWindow
{
protected:
	HWND hWnd = nullptr;
public:
	PrincipalWindow(HINSTANCE hInstance, wchar_t* lpCmdLine);
	PrincipalWindow(const PrincipalWindow&) = delete;
	PrincipalWindow& operator=(const PrincipalWindow&) = delete;
	~PrincipalWindow();
	const std::wstring& GetArgs() const 
	{
		return wstringArgs;
	}
	bool ProcessMessage();

private:
	static LRESULT WINAPI _HandleMsgSetup(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static LRESULT WINAPI _HandleMsgThunk(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT HandleMsg(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static constexpr wchar_t* wndClassName = L"Metavix principal window";
	HINSTANCE hInstance = nullptr;	
	std::wstring wstringArgs;
	
};