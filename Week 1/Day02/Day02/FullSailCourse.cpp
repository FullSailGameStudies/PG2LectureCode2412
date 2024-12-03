#include "FullSailCourse.h"
#include <iostream>

//2) create the definition. DO NOT forget the "FullSailCourse::"
void FullSailCourse::FillTheGrades(std::vector<float>& grades) const
{
	for (size_t i = 0; i < 10; i++)
	{
		grades.push_back((rand() % 10001) / 100.0F);
	}
}

void FullSailCourse::PrintGrades(const std::vector<float>& grades) const
{
    //FillTheGrades(grades);
    //grades.clear();
    //name_ = "SPR";
    std::cout << "\n" << name_ << "\n";
    for (auto& grade : grades)
    {
        std::cout << grade << "\n";
    }
}

void FullSailCourse::CalculateStats(const std::vector<float>& grades, float& min, float& max) const
{
    //min = 101, max = -1;
    min = max = grades[0];//ASSUMES grades has at least 1 grade
    for (int i = 1; i < grades.size(); i++)
    {
        if (min > grades[i])
        {
            min = grades[i];
        }
        if (max < grades[i]) max = grades[i]; 
    }
}
