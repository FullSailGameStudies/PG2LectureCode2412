#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:
	Pistol(int range, int damage, int rounds, int magCapacity) :
		Weapon(range, damage),
		rounds_(rounds), magCapacity_(magCapacity)
	{
	}

	int Rounds() const { return rounds_; }
	void Rounds(int newRounds) {
		if (newRounds <= magCapacity_ && newRounds >= 0)
			rounds_ = newRounds;
	}
	int MagCapacity() const { return magCapacity_; }
	void MagCapacity(int magCap)
	{
		if (magCap > 0 && magCap <= 30)
		{
			magCapacity_ = magCap;
		}
	}

private:
	int rounds_, magCapacity_;

};

