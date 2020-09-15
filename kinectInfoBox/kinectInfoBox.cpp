// kinectInfoBox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include <iostream>
//#include <sstream>
#include <Windows.h>
#include <windowsx.h>
//#include <NuiApi.h>
//#include <thread>
//#include <chrono>

#include "PrincipalWindow.h"





int WINAPI wWinMain(HINSTANCE hInstance, // abrbreviation for "handle to an instance". It is a 32-bit integer (instance is acopy of an application)
	HINSTANCE hPrevInstance,  // "handle to the previous instance" it detects any running copies (obsolete
	LPTSTR lpCmdLine,  // long pointer to a strng that contains the command line calling existence to the application
	int nCmdShow) // indicates how the windows is to appear when created 
{
	PrincipalWindow wnd(hInstance, lpCmdLine);
	while (wnd.ProcessMessage()) {
		// Do the graphic proccess
	}

}
