#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int fileWordCounter()
{
	ifstream fileReader("jabberwocky.txt");
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

	fileReader.close();
	return count;
}

int fileLineCounter()
{
	ifstream fileReader("jabberwocky.txt");
	if (!fileReader)
	{
		cerr << "File didn't open" << endl;
		system("pause");
		exit(1);
	}

	int count = 0;
	string lines;
	while (getline(fileReader, lines))
	{
		cout << lines << endl;
		count++;
	}
	return count;
}

void displayWordCount(int wordCount)
{
	cout << "\nthere are " << wordCount << " words in this file." << endl;
}

void displayLineCount(int lineCount)
{
	cout << "there are " << lineCount << " lines in this file." << endl;
}

int main()
{
	int lineCount = fileLineCounter();
	int wordCount = fileWordCounter();
	
	displayWordCount(wordCount);
	displayLineCount(lineCount);

	system("pause");
	return 0;
}