#include <iostream>
#include <string>
#include <vector>
#include "student.h"

using namespace brooklynpoly;

void Student::setName(std::string name)
{
	studentName = name;
}

std::string Student::getName()
{
	return studentName;
}