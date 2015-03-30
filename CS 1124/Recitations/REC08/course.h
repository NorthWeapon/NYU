#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace brooklynpoly
{
	class Registrar;
	class Student;
	class Course
	{
	private:
		std::string courseName;
		std::vector<Student*> enrolledStudents;
	public:
		Course() {};
		Course(std::string name) : courseName(name) {}
		void setName(std::string name);
		std::string getName();
		void addStudent(Student* student);
		std::vector<Student*> getEnrolledStudents();
	};
};

#endif