#include "Rational.h"
#include <stdexcept>
#include <cstdlib> 

// Overloading the stream insertion operator to print a rational number.
std::ostream& operator<<(std::ostream& output, const Rational& r)
{
	output << r.numerator << "/" << r.denominator;

	return output;
}
// Non-member function for recursive Euclidean Algorithm to find gcd.
int greatest_common_divisor(int a, int b)
{
	a = abs(a), b = abs(b); // negative integers have same divisor as positive integers.

	if (b == 0)
	{
		return a;
	}
	else
	{
		return greatest_common_divisor(b, a % b);
	}
}
// Constructor
Rational::Rational(int a, int b)
{
	numerator = a;
	denominator = b; // assuming a non-zero denominator.

	if (b == 0)
		throw std::invalid_argument("Denominator cannot be zero.");

	reduce();
}
// Member function to reduce fractions to lowest terms.
void Rational::reduce()
{
	int gcd = greatest_common_divisor(numerator, denominator);

	numerator = numerator / gcd;
	denominator = denominator / gcd;

	if (denominator < 0)
		numerator = -numerator, denominator = -denominator;
}
// Member function to set rational-number object following instantiation.
void Rational::set_number(int a, int b)
{
	numerator = a; denominator = b;
}
// Overloading the + operator to add two rational numbers.
Rational Rational::operator+(const Rational& a) const
{
	Rational result;

	// cross-multiply, then add together.
	result.numerator = numerator * a.denominator + a.numerator * denominator;
	result.denominator = denominator * a.denominator;
	result.reduce();

	return result;
}

Rational Rational::operator-(const Rational& a) const
{
	Rational result;

	// cross-multiply, then subtract
	result.numerator = numerator * a.denominator - a.numerator * denominator;
	result.denominator = denominator * a.denominator;
	result.reduce();

	return result;
}

Rational Rational::operator*(const Rational& a) const
{
	Rational result;

	// multiply numerator and denominator of each rational
	result.numerator = numerator * a.numerator;
	result.denominator = denominator * a.denominator;
	result.reduce();

	return result;
}

Rational Rational::operator/(const Rational& a) const
{
	Rational result;

	//cross multiply for division
	result.numerator = numerator * a.denominator;
	result.denominator = denominator * a.numerator;
	result.reduce();

	return result;
}

bool operator<(const Rational& lhs, const Rational& rhs)
{
	//Multiply to find common denominator and store numerator in int
	int lhs_numerator = lhs.numerator * rhs.denominator;
	int rhs_numerator = rhs.denominator * lhs.denominator;

	return(lhs_numerator < rhs_numerator);
}

bool operator>(const Rational& lhs, const Rational& rhs)
{
	//Returns the NOT of < operator, returns true if lhs > rhs
	return(!(lhs < rhs));
}

bool operator==(const Rational& lhs, const Rational& rhs)
{
	//LHS numerator and denominator need to equal RHS numerator and denominator to return true
	return(lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator);
}

bool operator!=(const Rational& lhs, const Rational& rhs)
{
	//Returns the NOT of == operator, returns true if lhs(n&d) != rhs(n&d)
	return(!(lhs == rhs));
}

/*
//Rational.h
// Rational.h
// A rational number class.
#include <iostream>

class Rational {
	friend std::ostream& operator<<(std::ostream&, const Rational&);
public:
	Rational(): numerator(), denominator(1) {  }
	Rational(int, int);						// Constructor now validates object
	void reduce();
	void set_number(int, int);
	Rational operator+(const Rational&) const; 						//Addition
	Rational operator-(const Rational&) const;						// Subtraction
	Rational operator*(const Rational&) const;						// Multiplication
	Rational operator/(const Rational&) const; 						// Division
	friend bool operator<(const Rational&, const Rational&);		// Less-than
	friend bool operator>(const Rational&, const Rational&);		// Greater-than
	friend bool operator==(const Rational&, const Rational&);		// Equal-to
	friend bool operator!=(const Rational&, const Rational&);		// Not-equal-to
private:
	int numerator;
	int denominator;
};*/