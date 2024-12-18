// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Console.h"
#include "Input.h"



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */



    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */
    std::string fileName = "pg2_2412.csv";
    std::string path = "C:\\temp\\2412\\", fullPath;
    fullPath = path + fileName;
    //1. open the file
    std::ofstream outFile(fullPath);
    char delimiter = '$';
    if (outFile.is_open())
    {
        //2. write the file
        //  << insertion operator
        outFile << "Superman is an alien." << delimiter << 5 << delimiter << 42.0;
        outFile << delimiter << true << delimiter << "Aquaman is 12 years old.";
    }
    else
        std::cout << fullPath << " could not be opened.\n";


    //3. close the file
    outFile.close();

    //1. open the file
    std::ifstream inFile(fullPath);
    if (inFile.is_open())
    {
        //2. read the file
        std::string line;
        std::getline(inFile, line);//reads 1 line from the file

        //parse the string to get the individual pieces of data
        std::string data;
        std::stringstream lineStream(line);
        std::getline(lineStream, data, delimiter);//tell getline what the delimiter is
        std::cout << data << "\n";

        std::getline(lineStream, data, delimiter);
        int iNum = std::stoi(data);
        std::cout << iNum << "\n";

        std::getline(lineStream, data, delimiter);
        double dNum = std::stod(data);
        std::cout << dNum << "\n";

        std::getline(lineStream, data, delimiter);
        //bool bVal = (data != "0");
        //if (data == "0") bVal = false;
        //else bVal = true;
        bool bVal = std::stoi(data);
        std::cout << bVal << "\n";

        std::getline(lineStream, data, delimiter);
        std::cout << data << "\n";
    }
    else
        std::cout << fullPath << " could not be opened.\n";

    //3. close the file
    inFile.close();



    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';

    std::stringstream multiStream(multi);
    while (!multiStream.eof())
    {
        //char tab = '\t';
        std::string hero;
        std::getline(multiStream, hero, collectionSeparator);

        std::string name, secret, ageStr;
        int age;
        std::stringstream heroStream(hero);
        std::getline(heroStream, name, objectSeparator);
        std::getline(heroStream, secret, objectSeparator);
        std::getline(heroStream, ageStr, objectSeparator);
        age = std::stoi(ageStr);

        std::cout << "Hello citizen! I am " << name << " (aka " << secret << ").";
        std::cout << " I am " << age << " years old!\n";
    }
}