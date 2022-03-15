// Rational.h
// A rational number class.
#include <iostream>

class Rational {
	friend std::ostream& operator<<(std::ostream&, const Rational&);
public:
	Rational(): numerator(), denominator(1) {  }
	Rational(int, int);							// Constructor now validates object
	void reduce();
	void set_number(int, int);
	Rational operator+(const Rational&) const; 	//Addition
	operator- 									// Subtraction
	operator* 									// Multiplication
	operator/								 	// Division
	operator<									// Less-than
	operator>									// Greater-than
	operator==									// Equal-to
	operator!=									// Not-equal-to
private:
	int numerator;
	int denominator;
};
