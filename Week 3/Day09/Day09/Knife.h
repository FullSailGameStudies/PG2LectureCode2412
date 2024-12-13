#pragma once
#include "Weapon.h"
class Knife : public Weapon
{
public:
	Knife(int range, int damage, int length_)
		: Weapon(range,damage),
		length_(length_)
	{
	}

	void showMe() override;

private:
	int length_;

};

