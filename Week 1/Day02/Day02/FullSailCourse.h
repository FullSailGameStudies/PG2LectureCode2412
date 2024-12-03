#pragma once
#include <string>
#include <vector>
class FullSailCourse
{
public:
	//1) create the declaration
	void FillTheGrades(std::vector<float>& grades) const;
	void PrintGrades(const std::vector<float>& grades) const;
	void CalculateStats(const std::vector<float>& grades, float& min, float& max) const;

	const std::string& GetName() { return name_; }
private:
	std::string name_ = "PG2";
};

