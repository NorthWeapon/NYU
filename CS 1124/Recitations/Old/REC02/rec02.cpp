#include <iostream>
#include <fstream>
#include <string>
//#include <stringstream>
#include <sstream>
#include <vector>
using namespace std;

struct Hydrocarbon
{
	string formula, name;
	int carbons;
}; 

Hydrocarbon hydrocarbons[100];

int countHydroCarbons()
{
	ifstream fileReader("hydrocarbons.txt");
	int hydrocarbonCount = 0;
	string name, formula; 

	while (fileReader >> name >> formula)
	{
		hydrocarbonCount++;
	}

	fileReader.close();
	return hydrocarbonCount;
}

int countMaxCarbons()
{
	ifstream fileReader("hydrocarbons.txt");
	string formula, name;
	char character;
	int carbons, maxCarbons = 0;

	while (fileReader >> name >> formula)
	{
		istringstream stringReader(formula);
		stringReader >> character >> character;
		carbons = character - 0;

		if (carbons > maxCarbons)
		{
			maxCarbons = carbons;
		}
	}
	return maxCarbons;
}

void sortHydrocarbons()
{
	for (int index = 0; index < maxCarbons; index++)
	{

	}
}

int main()
{
	system("pause");
	return 0;
}