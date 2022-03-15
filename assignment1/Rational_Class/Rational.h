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
};
