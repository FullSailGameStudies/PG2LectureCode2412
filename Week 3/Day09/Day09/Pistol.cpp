#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	Weapon::showMe();
	std::cout << "Mag Capacity: " << magCapacity_ << " Rounds: " << rounds_ << "\n";
}