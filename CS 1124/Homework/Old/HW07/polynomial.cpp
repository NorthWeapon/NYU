#include <iostream>
#include <vector>

class Polynomial
{
public:
	Polynomial() {}
	Polynomial(std::vector<int> coefficients) : degree(sizeof(coefficients) - 1) {}
	
	Polynomial& operator=(const Polynomial& polynomial)
	{
		return *this;
	}

	Polynomial& operator+=(const Polynomial& polynomial)
	{

	}

	Polynomial& operator+(const Polynomial& polynomial)
	{

	}

	bool operator==(const Polynomial& polynomial)
	{

	}

	bool operator!=(const Polynomial& polynomial)
	{

	}


	friend std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial);

	int evaluate(const int number)
	{

	}

private:
	int degree;
};

std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial)
{
	return os;
}

void doNothing(Polynomial temp) {}

int main() 
{
	//test constructor
	Polynomial p1({ 17 });
	Polynomial p2({ 1, 2 });
	Polynomial p3({ -1, 5 });
	Polynomial p4({ 5, 4, 3, 2, 1 });

	std::cout << "p1: " << p1 << std::endl;
	std::cout << "p2: " << p2 << std::endl;
	std::cout << "p3: " << p3 << std::endl;
	std::cout << "p4: " << p4 << std::endl;
	std::cout << "p2 + p3: " << (p2 + p3) << std::endl;
	std::cout << "p2 + p4: " << (p2 + p4) << std::endl;
	std::cout << "p4 + p2: " << (p4 + p2) << std::endl;


	//test copy constructor - the statement below uses the copy constructor
	//to initialize poly3 with the same values as poly4
	Polynomial p5(p4);
	p5 += p3;
	std::cout << "Polynomial p5(p4);\n" << "p5 += p3;\n";

	std::cout << "p4: " << p4 << std::endl;
	std::cout << "p5: " << p5 << std::endl;

	std::cout << "Calling doNothing(p5)\n";
	doNothing(p5);
	std::cout << "p5: " << p5 << std::endl;

	//tests the assignment operator
	Polynomial p6;
	std::cout << "p6: " << p6 << std::endl;
	std::cout << std::boolalpha;  //C auses bools true and false to be printed that way.
	std::cout << "(p4 == p6) is " << (p4 == p6) << std::endl;
	p6 = p4;
	std::cout << "p6: " << p6 << std::endl;
	std::cout << std::boolalpha;
	std::cout << "(p4 == p6) is " << (p4 == p6) << std::endl;

	//test the evaluaton
	int x = 5;
	std::cout << "Evaluating p1 at " << x << " yields: " << p1.evaluate(5) << std::endl;
	std::cout << "Evaluating p2 at " << x << " yields: " << p2.evaluate(5) << std::endl;

	Polynomial p7({ 3, 2, 1 }); // 3x^2 + 2x + 1
	std::cout << "p7: " << p7 << std::endl;
	std::cout << "Evaluating p7 at " << x << " yields: " << p7.evaluate(5) << std::endl;

	std::cout << std::boolalpha;
	std::cout << "(p1 == p2) is " << (p1 == p2) << std::endl;
	std::cout << "(p1 != p2) is " << (p1 != p2) << std::endl;

	system("pause");
	return 0;
}