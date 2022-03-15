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

	reduce();
}
// Member function to reduce fractions to lowest terms.
void Rational::reduce()
{	
	int gcd = greatest_common_divisor(numerator, denominator);

	numerator = numerator/gcd;
	denominator = denominator/gcd;

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
	result.numerator = numerator*a.denominator + a.numerator*denominator;
	result.denominator = denominator*a.denominator;
	result.reduce();

	return result;
}
