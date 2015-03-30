#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace brooklynpoly
{
	class Student
	{
	private:
		std::string studentName;
	public:
		Student() {};
		Student(std::string name) : studentName(name) {}

		void setName(std::string name);
		std::string getName();
	};
};

#endif