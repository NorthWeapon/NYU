#include <iostream>
#include <string>
#include <istream>

int GCD(int& numerator, int& denominator)
{
	while (denominator != 0)
	{
		int temp = numerator % denominator;
		numerator = denominator;
		denominator = temp;
	}
	return numerator;
}

class Rational
{
private:
	int numerator, denominator;
public:
	Rational() { normalize(); };
	//Rational(int num):denominator(num) {}; //constructor
	~Rational() {}; //destructor
	Rational(Rational &a)
	{
		normalize();
		numerator = a.numerator;
		denominator = a.denominator;
	}
	Rational(int inputNumber)
	{
		normalize();
		numerator = inputNumber;
	}
	Rational& operator=(const Rational &a)//assignment constructor
	{
		if (this != &a)
		{
			numerator = a.numerator;
			denominator = a.denominator;
			return *this;
		}
		else
		{
			return *this;
		}
	}

	int getNumerator() const
	{
		return numerator;
	}

	int getDenominator() const
	{
		return denominator;
	}

	void setNumerator(int paramNumerator)
	{
		numerator = paramNumerator;
	}

	void setDenominator(int paramDenominator)
	{
		denominator = paramDenominator;
	}

	void normalize()
	{
		int gcd = GCD(numerator, denominator);
		numerator = numerator / gcd;
		denominator = denominator / gcd;

		if (numerator < 0 && denominator < 0)
		{
			abs(numerator);
			abs(denominator);
		}
		else if (denominator < 0)
		{
			abs(denominator);
			numerator = 0 - numerator;
		}
	}
};

std::ostream& operator<<(std::ostream& os, const Rational& a)
{
	int numerator = a.getNumerator(), denominator = a.getDenominator();
	int commonDivisor = GCD(numerator, denominator);

	os << numerator << "/" << commonDivisor << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, Rational& a)
{
	int x, y;
	char slash;
	is >> x >> slash >> y;

	a.setNumerator(x);
	a.setDenominator(y);

	return is;
}

bool operator==(Rational& a, Rational& b) //if both rationals are equal
{
	return(a.getDenominator() == b.getDenominator() && a.getNumerator() == a.getNumerator());
}

bool operator!=(Rational& a, Rational& b) //if both rationals not equal
{
	return(a.getDenominator() != b.getDenominator() || a.getNumerator() != a.getNumerator());
}

Rational& operator+(Rational& a, Rational& b) //add rationals
{
	Rational c;
	if (a.getDenominator() != b.getDenominator())
	{
		c.setDenominator(a.getDenominator() * b.getDenominator()); // 3/4 + 4/5
		c.setNumerator(a.getNumerator() * b.getDenominator() + b.getNumerator() * a.getDenominator());
	}
	else
	{
		c.setDenominator(a.getDenominator());
		c.setNumerator(a.getNumerator() + b.getNumerator());
	}
	c.normalize();
	return(c);

}

Rational& operator--(Rational& a) //add 
{

}

Rational& operator--(Rational& a, int dummy)
{
	return a;
}
Rational& operator++(Rational& a)
{
	return a;
}
Rational& operator++(Rational& a, int dummy)
{

}

int main()
{
	Rational a, b;
	std::cout << "Input two rational numbers.\n";
	std::cout << "a: ";
	std::cin >> a;
	std::cout << "b: ";
	std::cin >> b;
	Rational one = 1;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "one = " << one << std::endl;
	std::cout << "a += b: " << (a += b) << std::endl;	             // Implement as member
	std::cout << "a = " << a << std::endl;
	std::cout << "a + one: " << (a + one) << std::endl;                // Implement as non-member, but not a friend
	std::cout << "a == one: " << boolalpha << (a == one) << std::endl;
	std::cout << "1 == one: " << boolalpha << (1 == one) << std::endl; // How does this work?
	std::cout << "a != one: " << boolalpha << (a != one) << std::endl; // Implement as non-member, but not a friend

	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << (++a) << std::endl;   // Implement as member
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << (a++) << std::endl;   // Implement as member
	std::cout << "a = " << a << std::endl;
	std::cout << "--a = " << (--a) << std::endl;   // Implement as non-member, but not a friend
	std::cout << "a = " << a << std::endl;
	std::cout << "a-- = " << (a--) << std::endl;   // Implement as non-member, but not a friend
	std::cout << "a = " << a << std::endl;

	// If time allows:
	// cout << "==========================\n";
	// cout << "a < one: " << boolalpha << (a < one) << endl;    // Implement as friend
	// cout << "a <= one: " << boolalpha << (a <= one) << endl;  // Implement as non-member, non-friend
	// cout << "a > one: " << boolalpha << (a > one) << endl;    // Implement as non-member, non-friend
	// cout << "a >= one: " << boolalpha << (a >= one) << endl;  // Implement as non-member, non-friend
	// cout << "==========================\n";

	system("pause");
	return 0;
}