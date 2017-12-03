#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

std::string getFileContents(const std::string& filePath)
{
	std::cout << "Opening file: " << filePath << "\n";
	std::ifstream inFile(filePath);
	if (!inFile.is_open())
	{
		throw std::runtime_error("Unable to open file: " + filePath);
	}

	std::stringstream stream;

	stream << inFile.rdbuf();
	return stream.str();
}