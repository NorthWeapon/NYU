#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int fileWordCounter()
{
	ifstream fileReader("file.txt");
	if (!fileReader)
	{
		cerr << "File didn't open" << endl;
		system("pause");
		exit(1);
	}

	int count = 0;
	string words;
	while (fileReader >> words)
	{
		count++;
	}
	return count;
}

void displayWordCount(int wordCount)
{
	cout << "there are " << wordCount << " words in this file." << endl;
}

int main()
{
	int wordCount = fileWordCounter();
	displayWordCount(wordCount);

	system("pause");
	return 0;
}