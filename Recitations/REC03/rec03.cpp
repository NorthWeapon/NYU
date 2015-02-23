#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Sandwich
{
private:
	const int bread = 2;
	int cheese, tomatoes;
	double mustard, mayo;

public :
	Sandwich(int tomatoes = 2, int cheese = 1, double mustard = .05, double mayo = .01): tomatoes(tomatoes), cheese(cheese), 
		mustard(mustard), mayo(mayo), bread(2)
	{
	}

	void display()
	{
		cout << "Bread: " << bread << " Cheese: " << cheese << " Tomatoes: " << tomatoes << " Mustard " << mustard 
			<< " Mayonaise: " << mayo << endl;
	}

	int getCheese()
	{
		return cheese;
	}

	void setCheese(int amount)
	{
		cheese = amount;
	}

	int getTomatoes()
	{
		return tomatoes;
	}

	void setTomatoes(int amount)
	{
		tomatoes = amount;
	}

	double getMustard()
	{
		return mustard;
	}

	void setMustard(double amount)
	{
		mustard = amount;
	}

	double getMayo()
	{
		return mayo;
	}

	void setMayo(double amount)
	{
		mayo = amount;
	}
};

class sandwichTruck
{
private:
	vector<Sandwich> truckLoad;

public:
	void addSandwich(Sandwich sandwich)
	{
		truckLoad.push_back(sandwich);
	}

	void displaySandwiches()
	{
		cout << "Sandwiches: " << endl;

		for (int index = 0; index < truckLoad.size(); index++)
		{
			truckLoad[index].display();
		}
	}
};

int main()
{
	Sandwich customer1;

	Sandwich customer2;
	customer2.setMustard(0);

	Sandwich customer3(2, 2);

	Sandwich customer4;

	sandwichTruck truck;
	truck.addSandwich(customer1);
	truck.addSandwich(customer2);
	truck.addSandwich(customer3);
	truck.addSandwich(customer4);

	truck.displaySandwiches();

	cout << customer2.getMustard() << endl;

	system("pause");
	return 0;
}