//Minecraft c++ clone
//made by Christoffer G following the teachings of Hopson's Minecraft in C++/OpenGL tutorials
#include "Application.h"
#include "Config.h"
#include "SettingsParser.h"

#include <fstream>
#include <iostream>

#ifdef __WIN32
extern "C"
{
	//Enable dedicated graphics
	__declspec(dllexport) bool NvOptimusEnablement = true;
	__declspec(dllexport) bool AmdPowerXpressRequestHighPerformance = true;
}
#endif // __WIN32

namespace
{
	void loadConfig(Config& config);
	void displayInfo();
}

int main()
{
	Config config;
	loadConfig(config);
	displayInfo();

	std::cin.ignore();
	std::cout << "Loading game...\n";

	Application app(config);
	app.runLoop();
}



namespace
{
	void loadConfig(Config& config)
	{
		SettingsParser settings;
		if (!settings.loadFromFile("config.txt"))
		{
			std::cout << "Failed to open Config file" << std::endl;
		}

		settings.get("window_width", config.windowX);
		settings.get("window_height", config.windowY);
		// if "width" and "height" are not found in the settings file their values are untouched 
		// (meaning you can easily set defaults like shown above)
		settings.get("renderchunkdistance", config.renderChunkDistance);
		settings.get("renderviewdistance", config.renderViewDistance);
		settings.get("fov", config.fov);
		settings.get("fullscreen", config.isFullscreen);
		settings.get("gamma", config.gamma);
		settings.get("contrast ", config.contrast);
		settings.get("brightness ", config.brightness);
		settings.get("postProcess", config.postProcess);
		settings.get("culling", config.culling);
		settings.get("worldType", config.worldType);

		settings.print();
		std::cin.get();
	}

	void displayInfo()
	{
		std::ifstream inFile;
		inFile.open("info.txt");
		std::string line;
		while (std::getline(inFile, line))
		{
			std::cout << line << "\n";
		}
	}
}
