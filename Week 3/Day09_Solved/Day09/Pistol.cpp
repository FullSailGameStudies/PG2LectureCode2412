#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	Weapon::showMe();
	std::cout << "\tMag Capacity: " << magCapacity_ << " Rounds: " << rounds_ << "\n";
}