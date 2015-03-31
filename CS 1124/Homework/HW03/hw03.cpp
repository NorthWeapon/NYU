/*
Name: Syed Aman
NYU ID: N15737606
Assignment: Homework 03 "Assosciation"

Note: The output on the website says: "Torvalds defeats Gates", however, it should be "He's dead, Torvalds" according to the rules provided. Torvalds has more strength
than Gates before battle, therefore Gates should be dead after battle
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class Warrior
{
private:
	int warriorStrength;
	std::string warriorName;
public:
	Warrior() {};
	Warrior(std::string name, int strength) : warriorName(name), warriorStrength(strength) {};
	
	//getters
	std::string getName()
	{
		return warriorName;
	}
	int getStrength()
	{
		return warriorStrength;
	}

	//setters
	void setName(std::string name)
	{
		warriorName = name;
	}
	void setStrength(int strength)
	{
		warriorStrength = strength;
	}
};

class Noble
{
private:
	int nobleStrength;
	std::string nobleName, nobleWeapon;
	std::vector<Warrior*> army;
public:
	Noble() {};
	Noble(std::string name) : nobleName(name) {};

	void hire(Warrior* warrior)
	{
		army.push_back(warrior);
	}

	void fire(Warrior* warrior)
	{
		int index = -1;
		for (Warrior* i : army)
		{
			index++;

			if (warrior->getName() == i->getName())
			{
				army.erase(army.begin() + index);
			}
		}
	}

	void battle()
	{

	}

	void display()
	{

	}

	//getters
	std::string getName()
	{
		return nobleName;
	}

	//setters
	void setName(std::string name)
	{
		nobleName = name;
	}
};

void readFile()
{
	std::ifstream fileReader("warriors.txt");
	if (!fileReader)
	{
		std::cerr << "Error opening file!" << std::endl;
		system("pause");
		exit(1);
	}

	std::string firstString, name, weapon, words;
	int strength, warriorCount = 0, nobleCount = 0;

	//count how many warriors
	while (fileReader >> firstString)
	{
		if (firstString == "Warrior")
		{
			warriorCount++;
		}
	}
	
	//create a dynamic array of Warrior objects
	Warrior* warriors = new Warrior[warriorCount + 1];

	//reset pointer
	fileReader.close();
	fileReader.open("warriors.txt");

	//cout how many nobles
	while (fileReader >> firstString)
	{
		if (firstString == "Noble")
		{
			nobleCount++;
		}
	}

	//create a dynamic array of Noble objects
	Noble* nobles = new Noble[nobleCount + 1];

	//reset pointer
	fileReader.close();
	fileReader.open("warriors.txt");

	//define string stream to seperate string into multiple strings
	std::istringstream stringReader;

	//define Warriors based on input file
	for (int warriorID = warriorCount; warriorID > 0; warriorID--)
	{
		while (fileReader >> firstString)
		{
			if (firstString == "Warrior")
			{
				fileReader >> words;

				stringReader.str(words);
				name = name + stringReader.peek();

				fileReader >> name >> weapon >> strength;
				warriors[warriorID].setName(name);
				warriors[warriorID].setStrength(strength);
				warriors[warriorID].setWeapon(weapon);
				break;
			}
		}
	}

	//reset pointer
	fileReader.close();
	fileReader.open("warriors.txt");

	//define Nobles based on input file
	for (int nobleID = nobleCount; nobleID > 0; nobleID--)
	{
		while (fileReader >> firstString)
		{
			if (firstString == "Noble")
			{
				fileReader >> name >> weapon >> strength;
				nobles[nobleID].setName(name);
				nobles[nobleID].setStrength(strength);
				nobles[nobleID].setWeapon(weapon);
				break;
			}
		}
	}

	//reset pointer
	fileReader.close();
	fileReader.open("warriors.txt");
	
	std::ofstream fileWriter("output.txt");
	std::string opponent1, opponent1Weapon, opponent2, opponent2Weapon;
	int opponent1WarriorID, opponent2WarriorID, opponent1WarriorIDStrength, opponent2WarriorIDStrength;

	//perform actions based on input file
	while (fileReader >> firstString)
	{
		//output status
		if (firstString == "Status")
		{
			fileWriter << "There are: " << warriorCount << " warriors" << std::endl;
			for (int warriorID = warriorCount; warriorID > 0; warriorID--)
			{
				fileWriter << "Warrior: " << warriors[warriorID].getName() << ", weapon: " << warriors[warriorID].getWeapon() << ", " << warriors[warriorID].getStrength() << std::endl;
			}
		}
		//battle warriors
		if (firstString == "Battle")
		{
			fileReader >> opponent1 >> opponent2;
			for (int warriorID = 0; warriorID <= warriorCount; warriorID++)
			{
				if (warriors[warriorID].getName() == opponent1)
				{
					opponent1WarriorID = warriorID;
				}
				if (warriors[warriorID].getName() == opponent2)
				{
					opponent2WarriorID = warriorID;
				}
			}

			fileWriter << warriors[opponent1WarriorID].getName() << " battles " << warriors[opponent2WarriorID].getName() << std::endl;

			if (warriors[opponent1WarriorID].getStrength() == 0 && warriors[opponent2WarriorID].getStrength() == 0)
			{
				fileWriter << "Oh, NO! They're both dead! Yuck!" << std::endl;
			}
			else
			{
				opponent1WarriorIDStrength = warriors[opponent1WarriorID].getStrength();
				opponent2WarriorIDStrength = warriors[opponent2WarriorID].getStrength();

				warriors[opponent1WarriorID].setStrength(opponent1WarriorIDStrength - opponent2WarriorIDStrength);
				warriors[opponent2WarriorID].setStrength(opponent2WarriorIDStrength - opponent1WarriorIDStrength);

				if (warriors[opponent1WarriorID].getStrength() <= 0 && warriors[opponent2WarriorID].getStrength() <= 0)
				{
					fileWriter << "Mutual Annihilation: " << warriors[opponent1WarriorID].getName() << " and " << warriors[opponent2WarriorID].getName() << " die at each other's hands" << std::endl;
				}
				else if (warriors[opponent1WarriorID].getStrength() > 0 && warriors[opponent2WarriorID].getStrength() <= 0)
				{
					fileWriter << "He's dead " << warriors[opponent1WarriorID].getName() << std::endl;
				}
				else if (warriors[opponent1WarriorID].getStrength() <= 0 && warriors[opponent2WarriorID].getStrength() > 0)
				{
					fileWriter << "He's dead " << warriors[opponent2WarriorID].getName() << std::endl;
				}
				else if (warriors[opponent1WarriorID].getStrength() > 0 && warriors[opponent2WarriorID].getStrength() > 0 && warriors[opponent1WarriorID].getStrength() > warriors[opponent2WarriorID].getStrength())
				{
					fileWriter << warriors[opponent1WarriorID].getName() << " defeats " << warriors[opponent2WarriorID].getName() << std::endl;
				}
				else if (warriors[opponent1WarriorID].getStrength() > 0 && warriors[opponent2WarriorID].getStrength() > 0 && warriors[opponent1WarriorID].getStrength() < warriors[opponent2WarriorID].getStrength())
				{
					fileWriter << warriors[opponent2WarriorID].getName() << " defeats " << warriors[opponent1WarriorID].getName() << std::endl;
				}
				if (warriors[opponent1WarriorID].getStrength() < 0)
				{
					warriors[opponent1WarriorID].setStrength(0);
				}
				if (warriors[opponent2WarriorID].getStrength() < 0)
				{
					warriors[opponent2WarriorID].setStrength(0);
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