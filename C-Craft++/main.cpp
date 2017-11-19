//Minecraft c++ clone
//made by Christoffer G following the teachings of Hopson's Minecraft in C++/OpenGL tutorials

#include "Display.h"
#include "Application.h"

int main() 
{
	Display::Init();

	Application app;

	app.RunMainGameLoop();

	return 0;
}