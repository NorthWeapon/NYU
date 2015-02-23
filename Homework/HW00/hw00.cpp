/*Note:
I am newly enrolled into the class as of February 6th, 2015. I was given a time extension by Professor Kletenik to finish HW00 HW01 REC01 and REC02

Name: Syed Aman
NYU ID: N15737606
Assignment: Homework 00 "Caesar Cypher"

Note:
I am newly enrolled into the class as of February 6th, 2015. I was given a time extension by Professor Kletenik to finish HW00 HW01 REC01 and REC02
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

char decryptCharacter(char encryptedCharacter, int rotation)
{
	if (int(encryptedCharacter) <= 122 && int(encryptedCharacter) >= 97)
	{
		char decryptedCharacter;

		decryptedCharacter = char(encryptedCharacter - rotation);

		if (int(decryptedCharacter) < 97)
		{
			decryptedCharacter = char(decryptedCharacter + 26);
		}

		return decryptedCharacter;
	}
	else
	{
		return encryptedCharacter;
	}
}

string decryptString(string encryptedString, int rotation)
{
	string decryptedString;
	char encryptedCharacter, decryptedCharacter;

	for (int index(0); index < encryptedString.length(); index++) //loop through string char by char and use decryptCharacter() invidiually
	{
		encryptedCharacter = encryptedString[index];
		decryptedCharacter = decryptCharacter(encryptedCharacter, rotation);
		decryptedString.push_back(decryptedCharacter);
	}

	return decryptedString;
}

vector<vector<string>> reverseVector(vector<vector<string>> vectorOfVectors)
{
	vector<vector<string>> reversedVectorOfVectors;

	for (int index(vectorOfVectors.size() - 1); index > -1; index--) //reverse vectorOfVectors where #4 is #1 etc.
	{
		reversedVectorOfVectors.push_back(vectorOfVectors[index]);
	}

	return reversedVectorOfVectors;
}

void writeDecryptedLines(vector<vector<string>> vectorOfVectors)
{
	ofstream fileWriter("decrypted.txt");

	for (int index(0); index < vectorOfVectors.size(); index++)
	{
		for (int index1(0); index1 < vectorOfVectors[index].size(); index1++)
		{
			fileWriter << vectorOfVectors[index][index1] << " ";
		}

		fileWriter << endl;
	}
}


vector<vector<string>> decryptFile()
{
	char encryptedCharacter, decryptedCharacter;
	int rotation;
	string decryptedString, encryptedString, encryptedLine;

	ifstream fileReader("encrypted.txt");
	if (!fileReader)
	{
		cerr << "Error opening file!" << endl;
		exit(1);
	}

	fileReader >> rotation; //read first line as rotation value
	fileReader.close(); fileReader.open("encrypted.txt"); //reset fileReader pointer

	int count(0);
	vector<string> decryptedStringVector;
	vector<vector<string>> vectorOfVectors; //create a vector of vectors: a vector containing a series of decryptedStringVectors

	while (getline(fileReader, encryptedLine)) //loop through encrypted.txt line by line
	{
		if (count == 0)
		{
			//pass
		}
		else
		{
			istringstream stringReader(encryptedLine);

			while (stringReader >> encryptedString) //break one encryptedLine into a vector of multiple decryptedStrings
			{
				decryptedString = decryptString(encryptedString, rotation);
				decryptedStringVector.push_back(decryptedString);
			}
			vectorOfVectors.push_back(decryptedStringVector); //vector: 1st line vector, 2nd line vector, 3rd line vector, 4th line vector
			decryptedStringVector.clear();

		}
		count++;
	}

	vector<vector<string>> reversedVectorOfVectors = reverseVector(vectorOfVectors); //reverse vectorOfVectors where #4 is #1 etc.
	
	return reversedVectorOfVectors;
}

int main()
{
	vector<vector<string>> reversedVectorOfVectors = decryptFile();
	writeDecryptedLines(reversedVectorOfVectors);

	system("pause");
	return 0;
}