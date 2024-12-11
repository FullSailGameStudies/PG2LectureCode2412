#pragma once
#include "Car.h"
#include <iostream>
class FlyingCar : public Car  //is-a relationship
{
public:
	FlyingCar(int year, std::string make, std::string model, int maxAlt) :
		Car(year,make,model), //call the ctor
		mMaxAlt(maxAlt)
	{
		//mModelYear = year; DO NOT DUPLICATE what the base does
	}
	std::string vehicleInformation() override;

	void Stuff()
	{
		std::cout << mModelYear;
	}
private:
	int mMaxAlt;
};

