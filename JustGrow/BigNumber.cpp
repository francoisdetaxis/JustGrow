#include "BigNumber.h"

BigNumber::BigNumber()
{
	_value = 0;
	_exponent = 1;
}

BigNumber::BigNumber(float value, int exponent)
{
	//big nulmber should look something like this: 9.99E18
	_value = value;
	_exponent = exponent;

	while (_value > 10.0)
	{
		_value /= 10;
		_exponent++;
	}
}

BigNumber BigNumber::operator+(const BigNumber& nb)
{
	//result = this + nb
	BigNumber result;
	int thisExp, thisVal, nbExp, nbVal;
	thisExp = this->_exponent;
	thisVal = this->_value;
	nbExp = nb._exponent;
	nbVal = nb._value;

	//if difference in exponents is >= 3, return the largest nb
	if (this->_exponent >= nb._exponent + 3)
	{
		result._exponent = this->_exponent;
		result._value = this->_value;
		return result;
	}
	else if (nb._exponent >= this->_exponent + 3)
	{
		result._exponent = nb._exponent;
		result._value = nb._value;
		return result;
	}

	else //difference in exponents in 2 at most
	{
		if (this->_exponent > nb._exponent)
		{
			while (thisExp != nb._exponent) //make this and nb have the same exponent
			{
				thisVal *= 10;
				thisExp--;
			}
			result._value = thisVal + nbVal;
			result._exponent = nb._exponent;
		}
		else if (nb._exponent > this->_exponent)
		{
			while (nbExp != this->_exponent)
			{
				nbVal *= 10;
				nbExp--;
			}
			result._value = thisVal + nbVal;
			result._exponent = this->_exponent;
		}
		else //exponents are equal
		{
			result._value = this->_value + nb._value;
			result._exponent = this->_exponent;
		}
	}
	while (result._value > 10.0)
	{
		result._value /= 10;
		result._exponent++;
	}
	return result;
}

void BigNumber::print()
{
	std::cout << _value << "E" << _exponent << std::endl;
}
