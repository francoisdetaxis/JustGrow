#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class BigNumber
{
public:
	BigNumber();
	BigNumber(float value, int exponent);
	BigNumber operator*(const BigNumber& nb);
	BigNumber operator/(const BigNumber& nb);
	void operator/=(const BigNumber& nb);
	void operator*=(const BigNumber& nb);
	BigNumber operator+(const BigNumber& nb);
	BigNumber operator-(const BigNumber& nb);
	void operator+=(const BigNumber& nb);
	void operator-=(const BigNumber& nb);
	std::string asString();
private:
	float _value;
	int _exponent;
};
