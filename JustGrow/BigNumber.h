#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class BigNumber
{
public:
	BigNumber();
	static BigNumber min(BigNumber& a, BigNumber& b);
	bool operator==(const BigNumber& nb);
	bool operator!=(const BigNumber& nb);
	bool operator<(const BigNumber& nb);
	bool operator>(const BigNumber& nb);
	bool operator>=(const BigNumber& nb);
	bool operator<=(const BigNumber& nb);
	BigNumber operator*(const BigNumber& nb);
	BigNumber operator/(const BigNumber& nb);
	void operator/=(const BigNumber& nb);
	void operator*=(const BigNumber& nb);
	BigNumber operator+(const BigNumber& nb);
	BigNumber operator-(const BigNumber& nb);
	std::string asString(bool rounded);
	static double to_double(const BigNumber& nb);
	static int to_int(const BigNumber& nb);
	int asInt();
	void operator+=(const BigNumber& nb);
	void operator-=(const BigNumber& nb);

	template<typename T>
	BigNumber(T value, int exponent);

	template <typename T>
	bool operator==(const T& nb);

	template<typename T>
	bool operator!=(const T& nb);

	template<typename T>
	bool operator<(const T& nb);

	template<typename T>
	bool operator<=(const T& nb);

	template<typename T>
	bool operator>(const T& nb);

	template<typename T>
	bool operator>=(const T& nb);

	template<typename T>
	BigNumber operator*(const T& nb);

	template<typename T>
	BigNumber operator/(const T& nb);

	template<typename T>
	void operator/=(const T& nb);

	template<typename T>
	BigNumber operator+(const T& nb);

	template<typename T>
	void operator*=(const T& nb);

	template<typename T>
	void operator+=(const T& nb);

	template<typename T>
	BigNumber operator-(const T& nb);

	template<typename T>
	void operator-=(const T& nb);

	template<typename T>
	static BigNumber min(const T& a, const BigNumber& b);

	template<typename T>
	static BigNumber min(const BigNumber& a, const T& b);

	template<typename T>
	static BigNumber pow(const T& base, const int& exponent);

	float _value;
	int _exponent;
};

//NON MEMBER FUNCTION DEFINITIONS
template<typename T>
BigNumber operator+(const T& lhs, const BigNumber& rhs);

template<typename T>
BigNumber operator-(const T& lhs, const BigNumber& rhs);

template<typename T>
BigNumber operator*(const T& lhs, const BigNumber& rhs);

template<typename T>
BigNumber operator/(const T& lhs, const BigNumber& rhs);

//NON MEMBER FUNCTIONS CODE
template<typename T>
BigNumber operator+(const T& lhs, const BigNumber& rhs)
{
	BigNumber biglhs(lhs, 0);
	return biglhs + rhs;
}

template<typename T>
BigNumber operator-(const T& lhs, const BigNumber& rhs)
{
	BigNumber biglhs(lhs, 0);
	return biglhs - rhs;
}

template<typename T>
BigNumber operator*(const T& lhs, const BigNumber& rhs)
{
	BigNumber biglhs(lhs, 0);
	return  biglhs * rhs;
}

template<typename T>
BigNumber operator/(const T& lhs, const BigNumber& rhs)
{
	BigNumber biglhs(lhs, 0);
	return biglhs / rhs;
}

//MEMBER FUNCTIONS CODE

template <typename T>
BigNumber::BigNumber(T value, int exponent)
{
	//big nulmber should look something like this: 9.99E18
	_value = (float)value;
	_exponent = exponent;
	while (_value >= 10.0)
	{
		_value /= 10;
		_exponent++;
	}
}

template <typename T>
bool BigNumber::operator==(const T& rhs)
{
	BigNumber bigNb(rhs, 0);
	return *this == bigNb;
}

template <typename T>
bool BigNumber::operator!=(const T& rhs)
{
	BigNumber bigNb(rhs, 0);
	return *this != bigNb;
}

template <typename T>
bool BigNumber::operator<(const T& rhs)
{
	//this < nb ?
	BigNumber bigNb(rhs, 0);
	return *this < bigNb;
}

template <typename T>
bool BigNumber::operator<=(const T& rhs)
{
	//this <= nb ?
	BigNumber bigNb(rhs, 0);
	return *this <= bigNb;
}

template <typename T>
bool BigNumber::operator>(const T& rhs)
{
	//this > nb ?
	BigNumber bigNb(rhs, 0);
	return *this > bigNb;
}

template <typename T>
bool BigNumber::operator>=(const T& rhs)
{
	//this >= nb ?
	BigNumber bigNb(rhs, 0);
	return *this >= bigNb;
}

template <typename T>
BigNumber BigNumber::operator*(const T& rhs)
{
	//result = this * nb
	BigNumber bigNb(rhs, 0);
	return *this * bigNb;
}

template <typename T>
void BigNumber::operator*=(const T& rhs)
{
	//this = this *= nb
	BigNumber bigNb(rhs, 0);
	*this *= bigNb;
}

template <typename T>
BigNumber BigNumber::operator/(const T& rhs)
{
	//result = this / nb
	BigNumber bigNb(rhs, 0);
	return *this / bigNb;
}

template <typename T>
void BigNumber::operator/=(const T& rhs)
{
	//this = this /= nb
	BigNumber bigNb(rhs, 0);
	*this /= bigNb;
}

template <typename T>
BigNumber BigNumber::operator+(const T& rhs)
{
	//this = this + nb
	BigNumber bigNb(rhs, 0);
	return *this + bigNb;
}

template <typename T>
void BigNumber::operator+=(const T& rhs)
{
	//this = this += nb
	BigNumber bigNb(rhs, 0);
	*this += bigNb;
}

template <typename T>
BigNumber BigNumber::operator-(const T& rhs)
{
	//this = this - nb
	BigNumber bigNb(rhs, 0);
	return *this - bigNb;
}

template <typename T>
void BigNumber::operator-=(const T& rhs)
{
	//this = this -= nb
	BigNumber bigNb(rhs, 0);
	*this -= bigNb;
}

template <typename T>
BigNumber BigNumber::min(const T& a, const BigNumber& b)
{
	BigNumber bigA(a, 0);
	if (bigA <= b)
		return bigA;
	else
		return b;
}

template <typename T>
BigNumber BigNumber::min(const BigNumber& a, const T& b)
{
	BigNumber bigB(b, 0);
	if (a <= bigB)
		return a;
	else
		return bigB;
}

template <typename T>
BigNumber BigNumber::pow(const T& base, const int& exponent)
{
	BigNumber result(1, 0);
	BigNumber bigBase(base, 0);
	int exp = exponent;
	while (exp != 0)
	{
		result *= bigBase;
		exp--;
	}
	return result;
}
