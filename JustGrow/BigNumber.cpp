#include "BigNumber.h"

BigNumber::BigNumber()
{
	_value = 0;
	_exponent = 0;
}

BigNumber BigNumber::min(BigNumber a, BigNumber b)
{
	if (a <= b)
		return a;
	else
		return b;
}

bool BigNumber::operator==(const BigNumber& nb)
{
	if (this->_value == nb._value && this->_exponent == nb._exponent)
		return true;
	else
		return false;
}

bool BigNumber::operator!=(const BigNumber& nb)
{
	if (this->_value != nb._value || this->_exponent != nb._exponent)
		return true;
	else
		return false;
}

bool BigNumber::operator<(const BigNumber& nb)
{
	//this < nb ?
	if (this->_exponent == nb._exponent)
	{
		return this->_value < nb._value;
	}
	else if (this->_exponent < nb._exponent)
		return true;
	else
		return false;
}

bool BigNumber::operator>(const BigNumber& nb)
{
	//this > nb ?
	if (this->_exponent == nb._exponent)
	{
		return this->_value > nb._value;
	}
	else if (this->_exponent > nb._exponent)
		return true;
	else
		return false;
}

bool BigNumber::operator>=(const BigNumber& nb)
{
	//this >= nb ?
	if (this->_exponent == nb._exponent)
	{
		return this->_value >= nb._value;
	}
	else if (this->_exponent >= nb._exponent)
		return true;
	else
		return false;
}

bool BigNumber::operator<=(const BigNumber& nb)
{
	//this <= nb ?
	if (this->_exponent == nb._exponent)
	{
		return this->_value <= nb._value;
	}
	else if (this->_exponent <= nb._exponent)
		return true;
	else
		return false;
}

BigNumber BigNumber::operator*(const BigNumber& nb)
{
	//result = this * nb
	BigNumber result;
	result._value = this->_value * nb._value;
	result._exponent = this->_exponent + nb._exponent;

	while (result._value >= 10.0)
	{
		result._value /= 10;
		result._exponent++;
	}
	return result;
}

BigNumber BigNumber::operator/(const BigNumber& nb)
{
	//result = this / nb
	BigNumber result;
	result._value = this->_value / nb._value;
	result._exponent = this->_exponent - nb._exponent;

	while (result._value >= 10.0)
	{
		result._value /= 10;
		result._exponent++;
	}
	return result;
}

void BigNumber::operator/=(const BigNumber& nb)
{
	//this = this /= nb
	this->_value = this->_value / nb._value;
	this->_exponent = this->_exponent - nb._exponent;

	while (this->_value >= 10.0)
	{
		this->_value /= 10;
		this->_exponent++;
	}
	return;
}

void BigNumber::operator*=(const BigNumber& nb)
{
	//this = this *= nb
	this->_value = this->_value * nb._value;
	this->_exponent = this->_exponent + nb._exponent;

	while (this->_value >= 10.0)
	{
		this->_value /= 10;
		this->_exponent++;
	}
	return;
}

BigNumber BigNumber::operator+(const BigNumber& nb)
{
	//result = this + nb
	BigNumber result;
	float thisVal, nbVal;
	int thisExp, nbExp;
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
	while (result._value >= 10.0)
	{
		result._value /= 10;
		result._exponent++;
	}
	return result;
}

void BigNumber::operator+=(const BigNumber& nb)
{
	//this = this + nb
	float thisVal, nbVal;
	int thisExp, nbExp;
	thisExp = this->_exponent;
	thisVal = this->_value;
	nbExp = nb._exponent;
	nbVal = nb._value;

	//if difference in exponents is >= 3, return the largest nb
	if (this->_exponent >= nb._exponent + 3)
		return;
	else if (nb._exponent >= this->_exponent + 3)
	{
		this->_exponent = nb._exponent;
		this->_value = nb._value;
		return;
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
			this->_value = thisVal + nbVal;
			this->_exponent = nb._exponent;
		}
		else if (nb._exponent > this->_exponent)
		{
			while (nbExp != this->_exponent)
			{
				nbVal *= 10;
				nbExp--;
			}
			this->_value = thisVal + nbVal;
		}
		else //exponents are equal
		{
			this->_value = this->_value + nb._value;
		}
	}
	while (this->_value >= 10.0)
	{
		this->_value /= 10;
		this->_exponent++;
	}
	return;
}

void BigNumber::operator-=(const BigNumber& nb)
{
	//this = this - nb
	float thisVal, nbVal;
	int thisExp, nbExp;
	thisExp = this->_exponent;
	thisVal = this->_value;
	nbExp = nb._exponent;
	nbVal = nb._value;

	//if difference in exponents is >= 3, return the largest nb
	if (this->_exponent >= nb._exponent + 3)
		return;
	else if (nb._exponent >= this->_exponent + 3)
	{
		this->_exponent = nb._exponent;
		this->_value = nb._value;
		return;
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
			this->_value = thisVal - nbVal;
			this->_exponent = nb._exponent;
		}
		else if (nb._exponent > this->_exponent)
		{
			while (nbExp != this->_exponent)
			{
				nbVal *= 10;
				nbExp--;
			}
			this->_value = thisVal - nbVal;
		}
		else //exponents are equal
		{
			this->_value = this->_value - nb._value;
		}
	}
	while (this->_value >= 10.0)
	{
		this->_value /= 10;
		this->_exponent++;
	}
	return;
}

BigNumber BigNumber::operator-(const BigNumber& nb)
{
	//result = this - nb
	BigNumber result;
	float thisVal, nbVal;
	int thisExp, nbExp;
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
			result._value = thisVal - nbVal;
			result._exponent = nb._exponent;
		}
		else if (nb._exponent > this->_exponent)
		{
			while (nbExp != this->_exponent)
			{
				nbVal *= 10;
				nbExp--;
			}
			result._value = thisVal - nbVal;
			result._exponent = this->_exponent;
		}
		else //exponents are equal
		{
			result._value = this->_value - nb._value;
			result._exponent = this->_exponent;
		}
	}
	while (result._value >= 10.0)
	{
		result._value /= 10;
		result._exponent++;
	}
	return result;
}

std::string BigNumber::asString()
{
	//TODO FIX ?
	//rounding happening here --> loss of precision
	//ex: _value 1.997... will be rounded to "2.00"
	std::stringstream streamVal, streamExp;
	streamVal << std::fixed << std::setprecision(2) << _value;
	streamExp << std::fixed << std::setprecision(2) << _exponent;
	return streamVal.str() + "E" + streamExp.str();
}