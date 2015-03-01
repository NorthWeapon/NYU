/*
Assignment: Recitation 5, Assosciation and Delegation
Date: February 27, 2015
Name: Syed Aman
NYU ID: sna274
*/

//email REC for regrading to sn1449@nyu.edu

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Student
{
private:
	string studentName;
	vector<int> grades;

public:
	Student() //default constructor
	{
		grades.push_back(-1); grades.push_back(-1); grades.push_back(-1); grades.push_back(-1); grades.push_back(-1); grades.push_back(-1);
		grades.push_back(-1); grades.push_back(-1); grades.push_back(-1); grades.push_back(-1); grades.push_back(-1); grades.push_back(-1);
		grades.push_back(-1);
	}
	Student(string name) : studentName(name) //constructor
	{
		grades.push_back(-1); grades.push_back(-1); grades.push_back(-1); grades.push_back(-1); grades.push_back(-1); grades.push_back(-1);
		grades.push_back(-1); grades.push_back(-1); grades.push_back(-1); grades.push_back(-1); grades.push_back(-1); grades.push_back(-1);
		grades.push_back(-1);
	}
};

class Section
{
private:
	string sectionName, dayOfWeek, fileName;
	int startHour;
	vector<Student*> studentPointerVector; //stored references of all students

public:
	Section() {} //default constructor
	Section(string name, string day, int hour) : sectionName(name), dayOfWeek(day), startHour(hour) {} //constructor

	void addStudentsFromFile() //reads all the students listed in a .txt file and creates corresponding Student class objects out of them
	{
		string students;
		ifstream fileReader(sectionName + ".txt");
		if (!fileReader)
		{
			cout << "Error opening file" << sectionName + ".txt" << endl;
		}

		while (fileReader >> students)
		{
			studentPointerVector.push_back(new Student(students)); //stores the reference of student into studentPointers vector
		}
	}

	void display()
	{
		int startHour24 = startHour;
		string startHour12;

		if (startHour24 > 12) //convert 24 hour time to 12 hour time
		{
			startHour24 -= 12;
			startHour12 = to_string(startHour24) + "PM";
		}
		else if (startHour24 < 12)
		{
			startHour12 = to_string(startHour24) + "AM";
		}
		else if (startHour24 == 12)
		{
			startHour12 = to_string(startHour24) + "PM";
		}
		else if (startHour24 == 24)
		{
			startHour24 -= 12;
			startHour12 = to_string(startHour24) + "AM";
		}

		cout << "test " << sectionName << endl;
		cout << "Section: " << sectionName << "; " << dayOfWeek << " " << startHour12 << endl;
	}

	void clear();

	//getters
	string getSectionName()
	{
		return sectionName;
	}

	string getSectionDay()
	{
		return dayOfWeek;
	}

	int getSectionStartHour()
	{
		return startHour;
	}

	vector<Student*> getStudentPointers()
	{
		return studentPointerVector;
	}
};

class LabWorker
{
private:
	string workerName;
	Section workersSection;

public:
	LabWorker(string name) : workerName(name) {} //constructor

	void addSection(Section section)
	{
		workersSection = section;
	}

	/*void displayGrades() 
	{

		for (Section i : sectionVector)
		{

		}
	}*/
};


class TimeSlot
{
private:
	string dayOfWeek;
	int startHour; //Time: 24 hour notation
public:
};

int main()
{
	LabWorker moe("Moe"), jane("Jane");
	Section secA2("A2", "Tuesday", 16);

	secA2.addStudentsFromFile();
	secA2.display();

	moe.addSection(secA2);
	vector<int> grades{ 13, -1 };
	for (int i : grades)
	{
		cout << i << endl;
	}

	system("pause");
	return 0;
}