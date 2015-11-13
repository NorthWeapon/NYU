#include <iostream>
#include <string>
#include <vector>
#include "registrar.h"
#include "course.h"
#include "student.h"

using namespace brooklynpoly;

void Registrar::addStudent(std::string studentName)
{
	Student* student = new Student;

	student->setName(studentName);
	registeredStudents.push_back(student);
}

void Registrar::addCourse(std::string courseName)
{
	Course* course = new Course;

	course->setName(courseName);
	registeredCourses.push_back(course);
}

void Registrar::enrollStudentInCourse(std::string studentName, std::string courseName)
{
	for (Course* i : registeredCourses)
	{
		if (i->getName() == courseName)
		{
			for (Student* j : registeredStudents)
			{
				if (j->getName() == studentName)
				{
					i->addStudent(j);
				}
			}
		}
	}
}

void Registrar::cancelCourse(std::string courseName)
{
	int index = -1;
	for (Course* i : registeredCourses)
	{
		index++;
		if (i->getName() == courseName)
		{
			registeredCourses.erase(registeredCourses.begin() + index);
			break;
		}
	}
}

void Registrar::printReport()
{
	std::cout << "Registered Students: ";
	for (Student* h : registeredStudents)
	{
		std::cout << h->getName() << " ";
	}
	std::cout << std::endl;

	std::vector<Student*> enrolledStudents;
	for (Course* i : registeredCourses)
	{
		enrolledStudents = i->getEnrolledStudents();

		std::cout << "Registered Course: " << i->getName() << std::endl;

		std::cout << i->getName() << " Students: ";
		for (Student* j : enrolledStudents)
		{
			std::cout << j->getName() << " ";
		}
		std::cout << std::endl;
	}
}