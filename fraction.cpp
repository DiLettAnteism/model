#include "fraction.h"
#include <algorithm>
#include <iostream>
#include <string>

fraction::fraction(): positive(true), numerator(0), denominator(1) {}

fraction::fraction(int num): positive(num >= 0), numerator(abs(num)), denominator(1) {}

fraction::fraction(int _numerator, int _denominator): positive(_numerator * _denominator >= 0), numerator(abs(_numerator)), denominator(abs(_denominator)) {
	this->simplify();
}

fraction::fraction(const fraction &a) {
	positive = a.positive;
	numerator = a.numerator;
	denominator = a.denominator;
}

void fraction::simplify() {
	unsigned int temp = std::__gcd(numerator, denominator);
	numerator /= temp;
	denominator /= temp;
}

fraction fraction::opposite() {
	this->positive = !(this->positive);
	fraction ret = *this;
	this->positive = !(this->positive);
	return ret;
}

fraction fraction::reciprocal() {
	unsigned int nu = this->numerator;
	unsigned int de = this->denominator;
	this->numerator = de;
	this->denominator = nu;
	fraction ret = *this;
	this->numerator = nu;
	this->denominator = de;
	return ret;
}

fraction operator+(const fraction &a, const fraction &b) {
	fraction ret;
	ret.denominator = a.denominator * b.denominator;
	if (a.positive == b.positive) {
		ret.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
		ret.positive = a.positive;
	} else if (a.numerator * b.denominator >= b.numerator * a.denominator) {
		ret.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
		ret.positive = a.positive;
	} else {
		ret.numerator = b.numerator * a.denominator - a.numerator * b.denominator;
		ret.positive = b.positive;
	}
	
	ret.simplify();
	return ret;
}

fraction operator-(const fraction &a, const fraction &b) {
	fraction temp = b;
	return a + temp.opposite();
}

fraction operator*(const fraction &a, const fraction &b) {
	fraction ret;
	ret.positive = (a.positive == b.positive);
	ret.numerator = a.numerator * b.numerator;
	ret.denominator = a.denominator * b.denominator;
	ret.simplify();
	return ret;
}

fraction operator/(const fraction &a, const fraction &b) {
	fraction temp = b;
	return a * temp.reciprocal();
}

bool operator>(const fraction &a, const fraction &b) {
	if (a.positive && b.positive) {
		return a.numerator * b.denominator > b.numerator * a.denominator;
	}
	if (!a.positive && !b.positive) {
		return a.numerator * b.denominator < b.numerator * a.denominator;
	}
	if (a.positive) return true;
	return false;
}

bool operator<(const fraction &a, const fraction &b) {
	return b > a;
}

bool operator==(const fraction &a, const fraction &b) {
	if (a.positive != b.positive) return false;
	return a.numerator == b.numerator && a.denominator == b.denominator;
}

bool operator!=(const fraction &a, const fraction &b) {
	return !(a == b);
}

bool operator>=(const fraction &a, const fraction &b) {
	return a > b || a == b;
}

bool operator<=(const fraction &a, const fraction &b) {
	return a < b || a == b;
}

std::ostream& operator<<(std::ostream &output, const fraction &a) {
	std::string s;
	if (a.numerator == 0) {
		s.push_back('0');
		output << s;
		return output;
	}
	if (!a.positive) {
		s.push_back('-');
	}
	if (a.denominator == 1) {
		s.append(std::to_string(a.numerator));
	} else {
		s.append(std::to_string(a.numerator));
		s.append("/");
		s.append(std::to_string(a.denominator));
	}
	output << s;
	return output;
}

std::istream& operator>>(std::istream &input, const fraction &a) {
	// ...
	return input;
}