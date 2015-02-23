/*
Note:
I am newly enrolled into the class as of February 6th, 2015. I was given a time extension by Professor Kletenik to finish HW00 HW01 REC01 and REC02

Name: Syed Aman
NYU ID: N15737606
Assignment: Homework 01 "Structs"

Note:
I am newly enrolled into the class as of February 6th, 2015. I was given a time extension by Professor Kletenik to finish HW00 HW01 REC01 and REC02
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct Warrior
{
	int strength;
	string name;
};

void readFile()
{
	ifstream fileReader("warriors.txt");
	if (!fileReader)
	{
		cerr << "Error opening file!" << endl;
		system("pause");
		exit(1);
	}

	string firstString, name;
	int strength, warriorCount = 0;

	//count how many warriors
	while (fileReader >> firstString)
	{
		if (firstString == "Warrior")
		{
			warriorCount++;
		}
	}

	Warrior warriors[15];

	//reset pointer
	fileReader.close();
	fileReader.open("warriors.txt");

	for (int warriorID = warriorCount; warriorID > 0; warriorID--)
	{
		while (fileReader >> firstString)
		{
			if (firstString == "Warrior")
			{
				fileReader >> name >> strength;
				warriors[warriorID].name = name;
				warriors[warriorID].strength = strength;
				break;
			}
		}
	}

	//reset pointer
	fileReader.close();
	fileReader.open("warriors.txt");
	ofstream fileWriter("output.txt");
	string opponent1, opponent2;
	int opponent1WarriorID, opponent2WarriorID, opponent1WarriorIDStrength, opponent2WarriorIDStrength;

	while (fileReader >> firstString)
	{
		if (firstString == "Status")
		{
			fileWriter << "There are: " << warriorCount << " warriors" << endl;
			for (int warriorID = warriorCount; warriorID > 0; warriorID--)
			{
				fileWriter << "Warrior: " << warriors[warriorID].name << ", strength: " << warriors[warriorID].strength << endl;
			}
		}
		if (firstString == "Battle")
		{
			fileReader >> opponent1 >> opponent2;
			for (int warriorID = 0; warriorID <= warriorCount; warriorID++)
			{
				if (warriors[warriorID].name == opponent1)
				{
					opponent1WarriorID = warriorID;
				}
				if (warriors[warriorID].name == opponent2)
				{
					opponent2WarriorID = warriorID;
				}
			}

			fileWriter << warriors[opponent1WarriorID].name << " battles " << warriors[opponent2WarriorID].name << endl;

			if (warriors[opponent1WarriorID].strength == 0 && warriors[opponent2WarriorID].strength == 0)
			{
				fileWriter << "Oh, NO! They're both dead! Yuck!" << endl;
			}
			else
			{
				opponent1WarriorIDStrength = warriors[opponent1WarriorID].strength;
				opponent2WarriorIDStrength = warriors[opponent2WarriorID].strength;

				warriors[opponent1WarriorID].strength = opponent1WarriorIDStrength - opponent2WarriorIDStrength;
				warriors[opponent2WarriorID].strength = opponent2WarriorIDStrength - opponent1WarriorIDStrength;

				if (warriors[opponent1WarriorID].strength <= 0 && warriors[opponent2WarriorID].strength <= 0)
				{
					fileWriter << "Mutual Annihilation: " << warriors[opponent1WarriorID].name << " and " << warriors[opponent2WarriorID].name << " die at each other's hands" << endl;
				}
				else if (warriors[opponent1WarriorID].strength > 0 && warriors[opponent2WarriorID].strength <= 0)
				{
					fileWriter << "He's dead " << warriors[opponent1WarriorID].name << endl;
				}
				else if (warriors[opponent1WarriorID].strength <= 0 && warriors[opponent2WarriorID].strength > 0)
				{
					fileWriter << "He's dead " << warriors[opponent2WarriorID].name << endl;
				}
				else if (warriors[opponent1WarriorID].strength > 0 && warriors[opponent2WarriorID].strength > 0 && warriors[opponent1WarriorID].strength > warriors[opponent2WarriorID].strength)
				{
					fileWriter << warriors[opponent1WarriorID].name << " defeats " << warriors[opponent2WarriorID].name << endl;
				}
				else if (warriors[opponent1WarriorID].strength > 0 && warriors[opponent2WarriorID].strength > 0 && warriors[opponent1WarriorID].strength < warriors[opponent2WarriorID].strength)
				{
					fileWriter << warriors[opponent2WarriorID].name << " defeats " << warriors[opponent1WarriorID].name << endl;
				}
				if (warriors[opponent1WarriorID].strength < 0)
				{
					warriors[opponent1WarriorID].strength = 0;
				}
				if (warriors[opponent2WarriorID].strength < 0)
				{
					warriors[opponent2WarriorID].strength = 0;
				}
			}
		}
	}

}

int main()
{
	readFile();
	system("pause");
	return 0;
}