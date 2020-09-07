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
	std::string asString();
	static BigNumber min(BigNumber a, BigNumber b);
	static BigNumber pow(float base, int exponent);

	//operators overload
	//comparison
	bool operator==(const BigNumber& nb);
	bool operator!=(const BigNumber& nb);
	bool operator<(const BigNumber& nb);
	bool operator>(const BigNumber& nb);
	bool operator>=(const BigNumber& nb);
	bool operator<=(const BigNumber& nb);
	//arithmetic ops
	BigNumber operator*(const BigNumber& nb);
	BigNumber operator/(const BigNumber& nb);
	void operator/=(const BigNumber& nb);
	void operator*=(const BigNumber& nb);
	BigNumber operator+(const BigNumber& nb);
	BigNumber operator-(const BigNumber& nb);
	void operator+=(const BigNumber& nb);
	void operator-=(const BigNumber& nb);

private:
	float _value;
	int _exponent;
};
