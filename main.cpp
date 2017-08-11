#include <windows.h>
#include "include/cef_app.h"

int APIENTRY wWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine,
	int nCmdShow) {

	CefMainArgs main_args(hInstance);

	int exit_code = CefExecuteProcess(main_args, NULL, NULL);
	if (exit_code >= 0)
	{
		return exit_code;
	}
	// Initialize CEF.
	CefSettings settings;
	CefInitialize(main_args, settings, NULL, NULL);

	// Run the CEF message loop. This will block until CefQuitMessageLoop() is
	// called.
	CefRunMessageLoop();

	// Shut down CEF.
	CefShutdown();
	return 0;
}