#include "FlyingCar.h"

std::string FlyingCar::vehicleInformation()
{
    //do I EXTEND the base method or FULL-OVERRIDE the base method?
    //EXTEND: add on to the base behavior by CALLING the base method
    //FULLY-OVERRIDE: a totally different behavior by NOT calling the base method
    std::string maxAlt = "\nMax Altitude: " + std::to_string(mMaxAlt);
    return Car::vehicleInformation() + maxAlt;//EXTEND the base
}
