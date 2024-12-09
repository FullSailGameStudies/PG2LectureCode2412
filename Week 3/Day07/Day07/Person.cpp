#include "Person.h"
#include <iostream>

void Person::ItsMyBirthday()
{
	age_++;
	std::cout << "I am " << name_ << "! It's my birthday! I am " << age_ << " years old! Let's have some cake!!\n";
}
