#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "registrar.h"

using namespace brooklynpoly;

void readTransactions()
{
	Registrar registrar;

	std::ifstream fileReader("transactions.txt");
	std::string word, courseName, studentName;

	while (fileReader >> word)
	{
		if (word == "PrintReport")
		{
			registrar.printReport();
		}
		else if (word == "AddCourse")
		{
			fileReader >> courseName;
			registrar.addCourse(courseName);
		}
		else if (word == "AddStudent")
		{
			fileReader >> studentName;
			registrar.addStudent(studentName);
		}
		else if (word == "EnrollStudentInCourse")
		{
			fileReader >> studentName >> courseName;
			registrar.enrollStudentInCourse(studentName, courseName);
		}
		else if (word == "CancelCourse")
		{
			fileReader >> courseName;
			registrar.cancelCourse(courseName);
		}
	}
}

int main()
{
	readTransactions();

	/*
	Registrar registrar;

	std::cout << "No courses or students added yet\n";
	registrar.printReport();

	std::cout << "AddCourse CS101.001\n";
	registrar.addCourse("CS101.001");
	registrar.printReport();

	std::cout << "AddStudent FritzTheCat\n";
	registrar.addStudent("FritzTheCat");
	registrar.printReport();

	std::cout << "AddCourse CS102.001\n";
	registrar.addCourse("CS102.001");
	registrar.printReport();

	std::cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
	registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
	std::cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
	registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
	registrar.printReport();

	std::cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
	std::cout << "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
	registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
	registrar.printReport();

	std::cout << "CancelCourse CS102.001\n";
	registrar.cancelCourse("CS102.001");
	registrar.printReport();
	*/
	/*
	// [OPTIONAL - do later if time]
	cout << "ChangeStudentName FritzTheCat MightyMouse\n";
	registrar.changeStudentName("FritzTheCat", "MightyMouse");
	cout << registrar << endl;  // or registrar.printReport()

	cout << "DropStudentFromCourse MightyMouse CS101.001\n";
	registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
	cout << registrar << endl;  // or registrar.printReport()

	cout << "RemoveStudent FritzTheCat\n";
	registrar.removeStudent("FritzTheCat");
	cout << registrar << endl;  // or registrar.printReport()
	*/

	/*
	std::cout << "Purge for start of next semester\n";
	registrar.purge();
	registrar.printReport();
	*/

	system("pause");
	return 0;
}