#include "DataReader.h"
#include <fstream>

void DataReader::DrawData()
{
	double w = Console::GetWindowWidth();
	double h = Console::GetWindowHeight();
	for (double y = 0; y < h; y++)
	{
		for (double x = 0; x < w; x++)
		{
			Console::SetCursorPosition(x, y);
			Console::SetBackgroundColor(GetColor(x / w, y / h));
			Console::Write(" ");
		}
	}
	Console::Reset();
}

ConsoleColor DataReader::GetColor(double xPercent, double yPercent)
{
	int x = xPercent * width_;
	int y = yPercent * height_;

	std::string& row = batData_[y];
	char color = row[x];
	if (color == '2')
		return ConsoleColor::Cyan;

	return ConsoleColor::Black;
}

void DataReader::ReadData()
{
	std::ifstream in("batBytes.dat");
	if (in.is_open())
	{
		std::string sizeStr;
		std::getline(in, sizeStr, ',');
		width_ = std::stoi(sizeStr);

		std::getline(in, sizeStr);
		height_ = std::stoi(sizeStr);

		batData_.clear();
		batData_.reserve(height_);

		std::string line;
		for (size_t i = 0; i < height_; i++)
		{
			std::getline(in, line);
			batData_.push_back(line);
		}
	}
	in.close();
}
