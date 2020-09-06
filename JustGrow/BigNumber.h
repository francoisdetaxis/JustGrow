#pragma once
#include <iostream>

class BigNumber
{
public:
	BigNumber();
	BigNumber(float value, int exponent);
	BigNumber operator+(const BigNumber& nb);
	void print();
private:
	float _value;
	int _exponent;

};

