// Day09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pistol.h"
#include <vector>
#include "Knife.h"


class base
{
private:
	int mNum;
public:
	base(int num) : mNum(num)
	{

	}
	void print()
	{
		std::cout << "Hello base " << mNum << "\n";
	}
};

class derived : public base
{
private:
	std::string mStr;
public:
	derived(std::string str, int num) : base(num), mStr(str)
	{ }
};


class Car
{
public:
	Car(int year)
	{
		mModelYear = year;
		mNumberOfCarsMade++;
	}

	int mModelYear; //each car has its own model year variable
	static int mNumberOfCarsMade; //shared by ALL cars

	//static methods:
	//  there is NO this parameter
	//	can ONLY access other static members (fields and methods)
	static void reporting()
	{
		//std::cout << "Model year: " << this->mModelYear << "\n"; //ERROR! cannot access non-static members
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}

	//non-static methods: 
	// there's a hidden parameter called 'this'
	//	can access non-static AND static members
	void vehicleInfo() 
	{
		std::cout << "Model Year: " << mModelYear << "\n";
	}
};
//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0;



int main()
{
	int n = 5;
	int* nPtr = &n;
	std::cout << n << "\n" << &n << "\n" << nPtr << "\n";
	std::cout << *nPtr << "\n";

	int nums[]{ 1,2,3,4,5 };
	//nPtr = nums;
	std::cout << "array\n";
	for (size_t i = 0; i < 15; i++)
	{
		std::cout << *nPtr << "\n";
		nPtr++;
	}

	{
		int* nPtr2 = new int(5);// "= new " means heap memory
		std::cout << "\nHeap Data\n" << *nPtr2 << "\n";
		nPtr = nPtr2;//copying the memory address
		delete nPtr2;//frees the allocated memory
	}

	std::cout << "\nHeap Data\n"<< *nPtr << "\n";
	/*
		╔════════════╗
		║ Unique_ptr ║
		╚════════════╝

		Using unique pointers w/ overridden methods


		╔═══════════╗
		║ UPCASTING ║ - casting a derived type variable to a base type variable
		╚═══════════╝

		This is ALWAYS safe.


		To maintain the original object, we need a pointer though. If not, then we're just calling the copy constructor of the base class and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);


		You can upcast by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move



		Lecture Code:
			use make_unique and unique_ptr to create a derived instance
			use std::move to upcast it to a base
	*/
	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";
	base1.print();



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/

	Weapon* wpnPtr = new Weapon(50, 100);
	Weapon* pWpn2 = wpnPtr;
	delete wpnPtr;
	wpnPtr = nullptr;
	if(wpnPtr != nullptr)
		wpnPtr->showMe();

	auto uWpnPtr = std::make_unique<Weapon>(50, 100);
	auto uWpnPtr3 = std::move(uWpnPtr);
	std::unique_ptr<Weapon> uWpnPtr2(new Weapon(50, 100));

	std::vector<std::unique_ptr<Weapon>> wpns;
	wpns.push_back(std::move(uWpnPtr3));
	wpns.push_back(std::make_unique<Pistol>(50, 100, 10, 15));//upcasting
	wpns.push_back(std::make_unique<Knife>(3, 10, 15));
	std::cout << "\nInventory:\n";
	for (auto& wpn : wpns)
	{
		wpn->showMe();//virtual. runtime polymorphism
		std::cout << "\n";
	}

	std::cout << "\nInventory:\n";
	std::vector<Weapon*> wpns2;
	wpns2.push_back(new Weapon(10, 20));
	wpns2.push_back(new Pistol(50, 100, 10, 15));//converting to a Weapon
	wpns2.push_back(new Knife(4, 10, 2));
	for (auto& wpn : wpns2)
	{
		wpn->showMe();//non-virtual 
		std::cout << "\n";
	}
	for (size_t i = 0; i < wpns2.size(); i++)
	{
		delete wpns2[i];
	}

	/*
		╔══════════════════╗
		║  Static Members  ║
		╚══════════════════╝

		When calling a non-static method on a class, you must use a variable of that class.
		That's because the variable is passed in as the 'this' parameter.

		Static methods do not have a 'this' parameter therefore you call them on the
		class name itself.

		That's also why static methods cannot access non-static members.

	*/
	Car myRide(1988);
	Car yourRide(2023);
	Car::reporting();
	myRide.vehicleInfo();//calling non-static methods. myRide is passed in for 'this'
	yourRide.vehicleInfo();
	/*

		CHALLENGE:
		Add a static method to the Car class that returns an instance of the Car class.

	*/
}