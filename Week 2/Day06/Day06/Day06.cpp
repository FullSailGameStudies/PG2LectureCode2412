// Day06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <Console.h>


enum class Weapon
{
    Sword, Axe, Spear, Mace
};

void Print(const std::map<std::string, double>& grades)
{
    std::cout << "\n\nJLA Univ Grades\n";
    for (auto& [student,grade] : grades)
    {
        ConsoleColor color =
            (grade < 59.5) ? ConsoleColor::Red :
            (grade < 69.5) ? ConsoleColor::Yellow :
            (grade < 79.5) ? ConsoleColor::Magenta :
            (grade < 89.5) ? ConsoleColor::Blue :
            ConsoleColor::Green;

        //if (grade < 59.5) color = ConsoleColor::Red;
        //else if (grade < 69.5) color = ConsoleColor::Yellow;
        //else if (grade < 79.5) color = ConsoleColor::Magenta;
        //else if (grade < 89.5) color = ConsoleColor::Blue;
        //else color = ConsoleColor::Green;

        Console::SetForegroundColor(color);
        std::cout << std::right << std::setw(7) << grade << " ";
        Console::Reset();
        Console::WriteLine(student);
    }
}

int main()
{

    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Removing a key and its value from a map  ]

        erase(iterator) -- returns an iterator that points to the first item AFTER the ones that were removed OR end() if no element exist
        erase(key) -- returns the # of items removed

    */
    std::map<Weapon, int> dorasBackpack;
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    dorasBackpack[Weapon::Axe] = 3;

    size_t numberRemoved = dorasBackpack.erase(Weapon::Sword);
    if (numberRemoved > 0)
        std::cout << "The Swords were removed.\n";
    else
        std::cout << "Sword was not found in the map.\n";

    std::map<Weapon, int>::iterator found = dorasBackpack.find(Weapon::Axe);
    if (found != dorasBackpack.end())
    {
        dorasBackpack.erase(found);
        std::cout << "The Axes were removed.\n";
    }
    else
        std::cout << "Axe was not found in the map.\n";





    /*
        CHALLENGE 1:

        print the students and grades below
            use std::setw and std::left and std::right to format the output
        ask for the name of the student to drop from the grades map
            use std::getline to get the user's input
        remove the student from the map
        print message indicating what happened
        if not found print an error message
        else print the map again and print that the student was removed


    */
    srand((unsigned int)time(NULL));
    std::map<std::string, double> grades;
    grades["Bruce"] = rand() % 10001 / 100.0;
    grades["Dick"] = rand() % 10001 / 100.0;
    grades["Diana"] = rand() % 10001 / 100.0;
    grades["Alfred"] = rand() % 10001 / 100.0;
    grades["Clark"] = rand() % 10001 / 100.0;
    grades["Arthur"] = rand() % 10001 / 100.0;
    grades["Barry"] = rand() % 10001 / 100.0;

    do
    {
        Print(grades);
        std::cout << "Student to drop: ";
        std::string name;
        std::getline(std::cin, name);
        if (name.empty()) break;

        auto foundStudent = grades.find(name);
        if (foundStudent == grades.end())
        {
            std::cout << name << " was not enrolled.\n";
        }
        else
        {
            grades.erase(foundStudent);
            //Print(grades);
            std::cout << name << " was dropped from the JLA University.\n";
        }

    } while (true);
}