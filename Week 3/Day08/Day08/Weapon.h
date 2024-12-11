#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	void showMe();
	virtual int calcDamage() = 0;//pure virtual function
	int calcDamage(int modifier);

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

