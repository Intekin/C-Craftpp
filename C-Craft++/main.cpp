
#include "Display.h"


int main() 
{
	Display::init();

	while (Display::isOpen())
	{
		Display::clear();
		Display::update();

		Display::checkForClose();
	}

}