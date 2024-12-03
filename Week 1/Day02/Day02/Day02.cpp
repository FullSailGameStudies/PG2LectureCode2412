#include <iostream>
#include <string>
#include <vector>
#include "FullSailCourse.h"

bool postFix(std::string& hero)
{
	//srand((unsigned int)time(NULL));
	int postFixNumber = rand() % 1000;
	hero = hero + "-" + std::to_string(postFixNumber);
	return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
	//scores.push_back(5); //not allowed because it is marked as const
	float sum = 0;
	for (auto score : scores)
		sum += score;

	return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
	std::cout << "----SCORES----\n";
	int index = 1;
	for (int score : scores)
		std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
	std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

bool Sum(int& number1, int& number2, int& sum)//prevents a copy (faster)
{
	std::cout << &number1 << "\t" << number1 << "\n";
	//number1 += 10;
	sum = number1 + number2;
	return sum % 2 == 0;
}
int Sum(std::vector<int>& nums)
{
	return 0;
}
int main()
{
	srand(time(NULL));//seed the random # generator
	//int result = Sum(5, 2);
	int n;
	int n1 = 5, n2 = 2;
	int& num1 = n1;
	std::cout << &n1 << "\t" << n1 << "\n";
	int result = 0;
	bool isSumEven = Sum(n1, n2, result);
	std::cout << &n1 << "\t" << n1 << "\n";
	int n3 = 10, n4 = 20;
	//result = Sum(n3, n4);

	std::vector<int> numbers{ 1,2,3,4,5,6,7,8,9,0 };
	std::cin.get();
	/*
		╔══════════════════════════════╗
		║Parameters: Pass by Reference.║
		╚══════════════════════════════╝
		Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

		NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
			This is because the parameter is actually just a new name for the other variable.
	*/
	std::string spider = "Spiderman";
	bool isEven = postFix(spider);
	std::string evenResult = (isEven) ? "TRUE" : "FALSE";
	std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


	/*
		CHALLENGE 1:

			add a method to FullSailCourse to fill the
			vector of floats with grades.
			1) pass it in by reference
			2) add 10 grades to the vector
			3) after calling the method in main, print out the vector

	*/
	std::vector<float> grades;
	FullSailCourse pg2;
	const std::string& name = pg2.GetName();
	pg2.FillTheGrades(grades);
	pg2.PrintGrades(grades);
	std::cin.get();


	/*
		╔══════════════════╗
		║ const parameters ║
		╚══════════════════╝
		const is short for constant. It prevents the variable from being changed in the method.

		This is the way you pass by reference and prevent the method from changing the variable.
	*/
	std::vector<int> highScores;
	highScores.reserve(10);
	printInfo(highScores);//size: 0  capacity: 0
	for (int i = 0; i < 10; ++i)
	{
		highScores.push_back(rand() % 5000);
		printInfo(highScores);//size: ?  capacity: ?
	}
	float avg = average(highScores);



	/*
		CHALLENGE 2:

			add a method to FullSailCourse to calculate
			the stats on a vector of grades
			1) create a method to calculate the min, max.
				pass the grades vector as a const reference.
				Use ref parameters for min and max.
			2) call the method in main and print out the min, max.

	*/
	float minGrade, maxGrade;
	pg2.CalculateStats(grades, minGrade, maxGrade);
	std::cout << "Min: " << minGrade << "\nMax: " << maxGrade << "\n";

	std::cin.get();



	/*
		╔═══════════╗
		║ vector<T> ║
		╚═══════════╝

		[  Removing from a vector  ]

		clear() - removes all elements from the vector
		erase(position) - removes the element at the position
		erase(starting position, ending position) - removes a range of elements. the end position is not erased.

	*/
	print(highScores);

	//erase all scores < 2500
	//for (int i = 0; i < highScores.size(); i++)
	//{
	//    if (highScores[i] < 2500)
	//    {
	//        highScores.erase(highScores.begin() + i);
	//        i--;
	//    }
	//}
	//OR...
	//for (int i = 0; i < highScores.size();)
	//{
	//    if (highScores[i] < 2500)
	//    {
	//        highScores.erase(highScores.begin() + i);
	//    }
	//    else
	//        i++;
	//}
	//for (int i = highScores.size() - 1; i >= 0; i--)
	//{
	//	if (highScores[i] < 2500)
	//	{
	//		highScores.erase(highScores.begin() + i);
	//	}
	//}
	for (auto i = highScores.begin(); i != highScores.end(); )
	{
		if (*i < 2500)
			i = highScores.erase(i);
		else
			i++;
	}

	print(highScores);



	/*
		CHALLENGE 3:

			Using the vector of grades you created.
			Remove all the failing grades (grades < 59.5).
			Print the grades.
	*/





	/*
		╔═══════════╗
		║ vector<T> ║
		╚═══════════╝


		size(): # of items that have been ADDED
		capacity(): length of the internal array
		reserve(n): presizes the internal array
	*/
	std::vector<int> scores;
	scores.reserve(10); //makes the internal array to hold 10 items.

	printInfo(scores);
}