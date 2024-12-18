#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

Car::Car(const std::string& csvData, char delim)
{
	DeserializeCSV(csvData, delim);
}

void Car::DeserializeCSV(const std::string& csvData, char delim)
{
	std::stringstream carStream(csvData);
	std::string data;
	std::getline(carStream, data, delim);
	mModelYear = std::stoi(data);
	std::getline(carStream, mMake, delim);
	std::getline(carStream, mModel, delim);
}

void Car::SerializeCSV(std::ostream& outFile, char delim) const
{
	outFile << mModelYear << delim << mMake << delim << mModel;
}
