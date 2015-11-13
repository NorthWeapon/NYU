#ifndef REGISTRAR_H
#define REGISTRAR_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace brooklynpoly
{
	class Student;
	class Course;
	class Registrar
	{
	private:
		std::vector<Student*> registeredStudents;
		std::vector<Course*> registeredCourses;
	public:
		void addStudent(std::string studentName);
		void addCourse(std::string courseName);
		void enrollStudentInCourse(std::string studentName, std::string courseName);
		void cancelCourse(std::string courseName);
		void printReport();
	};
};

#endif