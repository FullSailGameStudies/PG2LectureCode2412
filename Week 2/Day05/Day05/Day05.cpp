// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Console.h"
#include "Input.h"
#include <iomanip>

enum class Weapon
{
	Sword, Axe, Spear, Mace
};

const int NOT_FOUND = -1;

/// <summary>
/// Searches the vector using the linear search algorithm
/// </summary>
/// <param name="nums">the vector to search</param>
/// <param name="searchNum">the number to look for</param>
/// <returns>-1 if not found, the index of the item if found</returns>
int LinearSearch(const std::vector<int>& nums, int searchNum)
{
	int index = NOT_FOUND; //-1 is an invalid index so it indicates NOT FOUND
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == searchNum)
		{
			index = i;
			break;
		}
	}
	return index;
}

void PrintGrades(const std::map<std::string,double>& grades)
{
	std::cout << "\n\nPG2 Grades for 2412\n";
	for (auto& [name, grade] : grades)
	{
		ConsoleColor gradeColor =
			(grade < 59.5) ? ConsoleColor::Red : ConsoleColor::Green;//ternary
		Console::SetForegroundColor(gradeColor);
		std::cout << std::setw(7) << std::right;
		Console::Write(grade);
		Console::Reset();
		Console::WriteLine(" " + name);
	}
	std::cout << "\n\n";
}
int main()
{
	/*
		╔═════════╗
		║Searching║
		╚═════════╝

		There are 2 ways to search a vector: linear search or binary search

		CHALLENGE:

			write a method to linear search the numbers list.
				The method should take 2 parameters: vector of ints to search, int to search for.
				The method should return -1 if NOT found or the index if found.

			The algorithm:
				1) start at the beginning of the vector
				2) compare each item in the vector to the search item
				3) if found, return the index
				4) if reach the end of the vector, return -1 which means not found

	*/
	std::vector<int> numbers = { 0,1,2,3,4,5,6 };
	int searchNumber = 15;
	int foundIndex = LinearSearch(numbers, searchNumber);
	if (foundIndex == -1) std::cout << searchNumber << " was not found.\n";
	else std::cout << searchNumber << " was found at index " << foundIndex << "\n";

	searchNumber = 0;
	foundIndex = LinearSearch(numbers, searchNumber);
	if (foundIndex == -1) std::cout << searchNumber << " was not found.\n";
	else std::cout << searchNumber << " was found at index " << foundIndex << "\n";

	searchNumber = 6;
	foundIndex = LinearSearch(numbers, searchNumber);
	if (foundIndex == -1) std::cout << searchNumber << " was not found.\n";
	else std::cout << searchNumber << " was found at index " << foundIndex << "\n";



	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Creating a map  ]

		map<TKey, TValue>  - an associative collection.
			TKey is a placeholder for the type of the keys.
			TValue is a placeholder for the type of the values.

		When you want to create a map variable,
			1) replace TKey with whatever type of data you want to use for the keys
			2) replace TValue with the type you want to use for the values


		[  Adding items to a map  ]

		There are 2 ways to add items to a map:
		1) using the insert method.
		2) using [key] = value
	*/
	std::map<std::string, float> menu;
	menu["Dino Nuggies"] = 8.99F;
	menu["Cheese Burger"] = 12.99F;
	menu["Mac-n-cheese"] = 6.99F;
	menu["Mac-n-cheese"] = 7.99F;//overwrites the value

	std::pair<std::string, float> insertObj = std::make_pair("Chicken Tenders", 15.99F);
	auto wasInserted = menu.insert(insertObj);
	//first is the iterator to the pair object in the map
	//second is a bool saying whether it was inserted
	if (wasInserted.second) std::cout << insertObj.first << " was added.\n";
	else std::cout << insertObj.first << " was already on the menu.\n";

	insertObj.second = 20;
	wasInserted = menu.insert(insertObj);//will NOT overwrite

	std::cout << "\nC++ Cafe\n";
	for (auto& [menuItem, itemPrice] : menu)
	{
		std::cout << std::setw(7) << std::right << itemPrice;
		std::cout << " " << menuItem << "\n";
	}
	std::cout << "\n\n";


	std::cout << "\nC++ Cafe\n";
	for (auto iter = menu.begin(); iter != menu.end(); iter++)
	{
		std::cout << std::setw(7) << std::right << iter->second;
		std::cout << " " << iter->first << "\n";
	}
	std::cout << "\n\n";

	auto lamby = [](std::string msg) {
		std::cout << msg;
		};

	//lamby("DON'T DO THIS!!!\n");

	std::string itemToFind = "Mac-n-cheese";//key
	auto isFoundIter = menu.find(itemToFind);
	if (isFoundIter == menu.end())//not found
		std::cout << itemToFind << " was not found.\n";
	else
	{
		float oldPrice = isFoundIter->second;
		//menu[itemToFind]
		isFoundIter->second *= 1.05;
		std::cout << itemToFind << " used to costs " << oldPrice << ".\n";
		std::cout << "Now it costs " << menu[itemToFind] << "!! Thanks Putin!\n";
	}

	float price = menu["Hawaiian Pizza"];//don't do this if you simply want to find the key
	std::cout << "Hawaiian Pizza costs " << price << "\n";



	std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

	//returns an iterator and a bool. 
	//if the key is already in the map, it will NOT insert it -- the bool will be false.
	auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
	if (inserted.second == false) //meaning not inserted
		std::cout << "The key was already in the map. It was not inserted.\n";
	else
		std::cout << "The key was inserted in the map.\n";

	dorasBackpack[Weapon::Axe] = 3;
	dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


	/*
		CHALLENGE:

			Create a map that stores names (string) and grades. Call the variable grades.
			Add students and grades to your map.

	*/

	std::vector<std::string> students{ "Nigel", "Jacob",
	"Ja'Sohn", "Keith", "John", "Nathan", "Christian",
	"Alexander", "Donald", "Imani", "Jason", "Jeremy",
	"Josh", "Moni", "Payton", "Steven" };

	srand(time(NULL));
	std::map<std::string, double> grades;
	for (auto& student : students)
	{
		grades[student] = (rand() % 10001) / 100.0;
	}


	do
	{
		PrintGrades(grades);
		std::cout << "Name of student to curve: ";
		std::string nameOfStudent;
		std::getline(std::cin, nameOfStudent);
		if (nameOfStudent.empty()) break;

		auto foundStudent = grades.find(nameOfStudent);
		if (foundStudent == grades.end())
			std::cout << nameOfStudent << " was not in the course.\n";
		else
		{
			foundStudent->second = std::min(100.0, foundStudent->second + 5);
		}

	} while (true);

	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Looping over a map  ]

		You should use a ranged-based for loop when needing to loop over the entire map.

	*/
	for (auto const& [key, val] : dorasBackpack) //requires C++ 20
	{
		switch (key)
		{
		case Weapon::Sword:
			std::cout << "Sword: ";
			break;
		case Weapon::Axe:
			std::cout << "Axe: ";
			break;
		case Weapon::Spear:
			std::cout << "Spear: ";
			break;
		case Weapon::Mace:
			std::cout << "Mace: ";
			break;
		default:
			break;
		}
		std::cout << val << "\n";
	}


	/*
		CHALLENGE:

			Loop over your grades map and print each student name and grade.

	*/



	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Checking for a key in a map  ]

		use the find method to check if the key is in the map

		will return map.end() if NOT found.

	*/
	std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
	if (foundIter == dorasBackpack.end()) //meaning it was NOT found
	{
		std::cout << "Dora did not find any maces.\n";
	}
	else
	{
		//can safely grab the value for the key
		std::cout << "Dora found " << foundIter->second << " Maces\n";
	}



	/*
		CHALLENGE:

			look for a specific student in the map.
			If the student is found, print out the student's grade
			else print out a message that the student was not found

	*/




	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Updating a value for a key in a map  ]

		To update an exisiting value in the map, use the [ ]


	*/
	dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



	/*
		CHALLENGE:

			Pick any student and curve the grade (add 5) 
			that is stored in the grades map

	*/
}