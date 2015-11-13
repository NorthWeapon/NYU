#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::vector<std::string>> storeChemicalsFromFile()
{
	std::ifstream chemicalReader("chemicals.txt");

	std::string text, chemicalName, chemicalFormula;
	std::vector<std::string> nameFormulaVector;
	std::vector<std::vector<std::string>> hydrocarbonVector;
	while (chemicalReader >> text)
	{
		chemicalName = text;
		chemicalReader >> chemicalFormula;

		nameFormulaVector.push_back(chemicalName);
		nameFormulaVector.push_back(chemicalFormula);

		hydrocarbonVector.push_back(nameFormulaVector);

		//clear the vector
		nameFormulaVector.pop_back();
		nameFormulaVector.pop_back();
	}

	return hydrocarbonVector;
}

void printChemicalsFromVector(std::vector<std::vector<std::string>> &hydrocarbonVector)
{
	for (std::vector<std::string> nameFormulaVector : hydrocarbonVector)
	{
		for (std::string text : nameFormulaVector)
		{
			std::cout << text << " ";
		}

		std::cout << std::endl;
	}

	std::cout << "\n======================\n" << std::endl;

	for (int i = 0; i < hydrocarbonVector.size(); i++)
	{
		for (int j = 0; j < hydrocarbonVector[i].size(); j++)
		{
			std::cout << (hydrocarbonVector[i])[j] << " ";
		}

		std::cout << std::endl;
	}
}

int main()
{
	std::vector<std::vector<std::string>> hydrocarbonVector = storeChemicalsFromFile();
	printChemicalsFromVector(hydrocarbonVector);

	system("pause");
	return 0;
}