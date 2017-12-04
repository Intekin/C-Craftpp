#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

std::string getFileContents(const std::string& filePath)
{
	std::cout << "Try to open file: " << filePath << "\n";
	std::ifstream inFile(filePath);
	if (!inFile.is_open())
	{
		std::cout << "Failed opening file: " << filePath << "\n";
		throw std::runtime_error("Unable to open file: " + filePath);
	}

	std::stringstream stream;

	stream << inFile.rdbuf();
	std::cout << "Opend file: " << filePath << "\n";
	return stream.str();
}