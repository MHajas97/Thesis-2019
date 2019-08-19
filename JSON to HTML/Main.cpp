
#include "MainWindow.h"
#include "windows.h"
[System::STAThread]
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	System::Windows::Forms::Application::Run(%JSONtoHTML::MainWindow());
}