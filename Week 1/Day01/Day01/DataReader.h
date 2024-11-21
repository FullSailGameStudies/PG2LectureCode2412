#pragma once
#include <vector>
#include <string>
#include "Console.h"
class DataReader
{
public:
	DataReader()
	{
		ReadData();
	}

	void DrawData();

private:
	void ReadData();
	ConsoleColor GetColor(double, double);
	int width_, height_;
	std::vector<std::string> batData_;
};

