#include <iostream>
#include <string>
#include <vector>
#include "course.h"

using namespace brooklynpoly;

void Course::setName(std::string name)
{
	courseName = name;
}

std::string Course::getName()
{
	return courseName;
}

void Course::addStudent(Student* student)
{
	enrolledStudents.push_back(student);
}

std::vector<Student*> Course::getEnrolledStudents()
{
	return enrolledStudents;
}