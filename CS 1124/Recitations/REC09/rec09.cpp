/*
Syed Aman
Recitation 09
CS1124
Focus: Copy Control.  Uses dynamic array of pointers.
*/

#include <string>
#include <iostream>

class Position
{
private:
	std::string title;
	double salary;
public:
	Position() {}
	Position(const std::string& aTitle, double aSalary) : title(aTitle), salary(aSalary) {}

	//getters
	std::string getTitle() const
	{
		return title;
	}
	double getSalary() const
	{
		return salary;
	}

	//setters
	void changeSalaryTo(double d)
	{
		salary = d;
	}
};

class Entry
{
private:
	std::string name;
	unsigned int room, phone;
	Position* pos;
public:
	Entry() {}
	Entry(const std::string& aName, unsigned aRoom, unsigned aPhone, Position& aPosition) : name(aName), room(aRoom), phone(aPhone),
		pos(&aPosition) {}

	std::string getName()
	{
		return name;
	}
	unsigned getPhone()
	{
		return phone;
	}
	//overload << operator to display name, room, and phone
	friend std::ostream& operator<< (std::ostream& os, const Entry& e);
};

std::ostream& operator<<(std::ostream& os, const Entry& e)
{
	os << e.name << ' ' << e.room << ' ' << e.phone << std::endl;
	return os;
}

class Directory
{
private:
	Entry** entries;
	size_t size, capacity;
public:
	//constructor
	Directory() : capacity(2), size(0), entries(new Entry*[2])
	 {
		// Should we do this?  What do you think?
		for (size_t i = 0; i < capacity; i++) 
		{ 
			entries[i] = nullptr; 
		}
	}
	//copy constructor
	Directory(const Directory &directory) : capacity(directory.capacity), size(directory.size), entries(new Entry*[directory.capacity])
	{
		for (size_t i = 0; i < size; i++) 
		{
			entries[i] = new Entry(*directory.entries[i]); 
		}
	}
	//assignment operator
	Directory& operator=(Directory& directory)
	{
		if (this != &directory)
		{
			for (int i = 0; i < size; i++)
			{
				delete entries[i];
			}
			delete entries;
			size = directory.size;
			capacity = directory.capacity;

			entries = new Entry*[capacity];
			for (size_t i = 0; i < size; i++)
			{
				entries[i] = new Entry (*directory.entries[i]);
			}
		}
		return directory;
	}
	
	//descructor
	~Directory()
	{
		for (int i = 0; i < size; i++)
		{
			delete entries[i];
		}
		delete entries;
	}
	
	void add(const std::string& name, unsigned room, unsigned ph, Position& pos)
	{
		if (size == capacity)
		{
			Entry** temp = entries;
			entries = new Entry*[capacity *= 2];
			for (int i = 0; i < size; i++)
			{
				entries[i] = new Entry(* temp[i]);
				delete temp[i];
			}
		}
		entries[size] = new Entry(name, room, ph, pos);
		size++;
	}

	//overload << operator to call entry's operator overload
	friend std::ostream& operator<<(std::ostream& os, const Directory& d);

	size_t operator[](std::string name)
	{
		for (int i = 0; i < capacity; i++)
		{
			if (name == entries[i]->getName())
			{
				return entries[i]->getPhone();
			}
		}
		return -1;
	}
};

std::ostream& operator<<(std::ostream& os, const Directory & d)
{
	for (size_t i = 0; i < d.size; i++)
	{
		os << *(d.entries[i]) << std::endl;
	}

	return os;
}

void doNothing(Directory& dir) { std::cout << dir << std::endl; }

int main()
{
	// Model as if there are these four kinds 
	// of position in the problem:
	Position boss("Boss", 3141.59);
	Position pointyHair("Pointy Hair", 271.83);
	Position techie("Techie", 14142.13);
	Position peon("Peonissimo", 34.79);

	// Create a Directory
	Directory directory1;
	directory1.add("Marilyn", 123, 4567, boss);
	std::cout << directory1 << std::endl;
	
	Directory directory2 = directory1;	//using copy constructor
	directory2.add("Gallagher", 111, 2222, techie);
	directory2.add("Carmack", 314, 1592, techie);
	
	std::cout << directory2 << std::endl;
	
	std::cout << "Calling doNothing" << std::endl;
	doNothing(directory2);
	std::cout << "doNothing call completed" << std::endl;

	Directory directory3;
	directory3 = directory2; //using assignment operator
	
	std::cout << directory3["Gallagher"] << std::endl;

	std::system("pause");
	return 0;
}