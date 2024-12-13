#include "Knife.h"
#include <iostream>

void Knife::showMe()
{
	Weapon::showMe();
	std::cout << "Length: " << length_ << "\n";
}
