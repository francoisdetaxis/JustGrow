#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class BigNumber
{
public:
	BigNumber();
	std::string asString();
	static BigNumber min(BigNumber a, BigNumber b);
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
	void operator*=(const T& nb);

	template<typename T>
	BigNumber operator+(const T& nb);

	template<typename T>
	void operator+=(const T& nb);

	template<typename T>
	BigNumber operator-(const T& nb);

	template<typename T>
	void operator-=(const T& nb);

	template<typename T>
	static BigNumber min(T& a, BigNumber& b);

	template<typename T>
	static BigNumber min(BigNumber& a, T& b);

	template<typename T>
	static BigNumber pow(T base, int exponent);

private:
	float _value;
	int _exponent;
};

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
bool BigNumber::operator==(const T& nb)
{
	BigNumber bigNb(nb, 0);
	return *this == bigNb;
}

template <typename T>
bool BigNumber::operator!=(const T& nb)
{
	BigNumber bigNb(nb, 0);
	return *this != bigNb;
}

template <typename T>
bool BigNumber::operator<(const T& nb)
{
	//this < nb ?
	BigNumber bigNb(nb, 0);
	return *this < bigNb;
}

template <typename T>
bool BigNumber::operator<=(const T& nb)
{
	//this <= nb ?
	BigNumber bigNb(nb, 0);
	return *this <= bigNb;
}

template <typename T>
bool BigNumber::operator>(const T& nb)
{
	//this > nb ?
	BigNumber bigNb(nb, 0);
	return *this > bigNb;
}

template <typename T>
bool BigNumber::operator>=(const T& nb)
{
	//this >= nb ?
	BigNumber bigNb(nb, 0);
	return *this >= bigNb;
}

template <typename T>
BigNumber BigNumber::operator*(const T& nb)
{
	//result = this * nb
	BigNumber bigNb(nb, 0);
	return *this * bigNb;
}

template <typename T>
void BigNumber::operator*=(const T& nb)
{
	//this = this *= nb
	BigNumber bigNb(nb, 0);
	*this *= bigNb;
}

template <typename T>
BigNumber BigNumber::operator/(const T& nb)
{
	//result = this / nb
	BigNumber bigNb(nb, 0);
	return *this / bigNb;
}

template <typename T>
void BigNumber::operator/=(const T& nb)
{
	//this = this /= nb
	BigNumber bigNb(nb, 0);
	*this /= bigNb;
}

template <typename T>
BigNumber BigNumber::operator+(const T& nb)
{
	//this = this + nb
	BigNumber bigNb(nb, 0);
	return *this + bigNb;
}

template <typename T>
void BigNumber::operator+=(const T& nb)
{
	//this = this += nb
	BigNumber bigNb(nb, 0);
	*this += bigNb;
}

template <typename T>
BigNumber BigNumber::operator-(const T& nb)
{
	//this = this - nb
	BigNumber bigNb(nb, 0);
	return *this - bigNb;
}

template <typename T>
void BigNumber::operator-=(const T& nb)
{
	//this = this -= nb
	BigNumber bigNb(nb, 0);
	*this -= bigNb;
}

template <typename T>
BigNumber BigNumber::min(T& a, BigNumber& b)
{
	BigNumber bigA(a, 0);
	if (bigA <= b)
		return bigA;
	else
		return b;
}

template <typename T>
BigNumber BigNumber::min(BigNumber& a, T& b)
{
	BigNumber bigB(b, 0);
	if (a <= bigB)
		return a;
	else
		return bigB;
}

template <typename T>
BigNumber BigNumber::pow(T base, int exponent)
{
	BigNumber result(1, 0);
	BigNumber bigBase(base, 0);
	while (exponent != 0)
	{
		result *= bigBase;
		exponent--;
	}
	return result;
}
