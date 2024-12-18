﻿// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>
#include "Console.h"
#include "Input.h"

int main()
{
    std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items

    // <<  insertion operator  (OR bitshift left)
    // >>  extraction operator  (OR bitshift right)
    std::string fileName = "myGarage.csv";
    std::ofstream outFile(fileName);
    char delim = '^';
    if (outFile.is_open())
    {

        Car myRide(1969, "Plymouth", "Hemi Cuda");
        myRide.SerializeCSV(outFile, delim);
    }
    else
        std::cout << fileName << " could not be opened.\n";

    outFile.close();

    std::vector<Car> garage;
    garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
    garage.push_back(Car(1956, "Ford", "T Bird"));
    garage.push_back(Car(1961, "Porsche", "Speedster"));
    garage.push_back(Car(1965, "Pontiac", "GTO"));
    garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));

    outFile.open(fileName, std::ios_base::app);//will overwrite the existing file
    if (outFile.is_open())
    {
        bool first = true;
        for (auto& car : garage)
        {
            outFile << "\n";
            //first = false;

            car.SerializeCSV(outFile, delim);
        }
    }
    else
        std::cout << fileName << " could not be opened.\n";

    outFile.close();


    /*
        ╔═════════════╗
        ║ Serializing ║
        ╚═════════════╝

        Saving the state (data) of objects

        Lecture Code: serialize the vector of Cars to a file.
            Data Format:
                separates cars. EX: car1|car2|car3
                separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

    */



    /*
        ╔═══════════════╗
        ║ Deserializing ║
        ╚═══════════════╝

        Recreating the objects from the saved state (data) of objects

        Lecture Code:
            Open the file
            Read in each line
            split each line to get each car
            split each car to get the car details

    */

    std::vector<Car> jaysGarage;
    std::ifstream inFile(fileName);
    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            std::string line;
            std::getline(inFile, line);
            Car nextCar(line, delim);
            jaysGarage.push_back(nextCar);
        }
    }
    else
        std::cout << fileName << " could not be opened.\n";

    std::cout << "\nLeno's Garage\n";
    for (auto& car : jaysGarage)
    {
        car.SerializeCSV(std::cout, ' ');
        std::cout << "\n";
    }
}