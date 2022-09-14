#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class fraction {
public:
	friend fraction operator+(const fraction &a, const fraction &b);
	friend fraction operator-(const fraction &a, const fraction &b);
	friend fraction operator*(const fraction &a, const fraction &b);
	friend fraction operator/(const fraction &a, const fraction &b);
	friend bool operator>(const fraction &a, const fraction &b);
	friend bool operator<(const fraction &a, const fraction &b);
	friend bool operator>=(const fraction &a, const fraction &b);
	friend bool operator<=(const fraction &a, const fraction &b);
	friend bool operator==(const fraction &a, const fraction &b);
	friend std::ostream& operator<<(std::ostream &output, const fraction &a);
	friend std::istream& operator>>(std::istream &input, const fraction &a);

	fraction();
	fraction(int num);
	fraction(int _numerator, int _denominator);
	fraction(const fraction &a);

	void simplify();
	fraction opposite();
	fraction reciprocal();

private:
	bool positive;
	unsigned int numerator; // 分子
	unsigned int denominator; // 分母
};
#endif