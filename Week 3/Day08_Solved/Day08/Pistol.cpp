#include "Pistol.h"


void Pistol::showMe()
{
	Weapon::showMe();//extending the base version
	std::cout << "\tRounds: " << mRounds << " Magazine Capacity: " << mMagCapacity << "\n";
}