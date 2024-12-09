#pragma once
#include <string>
class Person
{
public:
	Person(int age,const std::string& name)// : age_(age), name_(name)
	{
		Age(age);
		Name(name);
	}
	
	void ItsMyBirthday();

	int Age() const { return age_; }
	void Age(int age)
	{
		if (age >= 0 && age <= 120)
			age_ = age;
	}

	const std::string& Name() const { return name_; }
	void Name(const std::string& name)
	{
		if (name.size() > 0 && name.size() < 128)
			name_ = name;
	}
private:
	int age_;
	std::string name_;
};

