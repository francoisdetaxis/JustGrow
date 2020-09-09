#include "BigNumber.h"

BigNumber::BigNumber()
{
	_value = 0;
	_exponent = 0;
}

BigNumber BigNumber::min(BigNumber& a, BigNumber& b)
{
	if (a <= b)
		return a;
	else
		return b;
}

bool BigNumber::operator==(const BigNumber& rhs)
{
	if (this->_value == rhs._value && this->_exponent == rhs._exponent)
		return true;
	else
		return false;
}

bool BigNumber::operator!=(const BigNumber& rhs)
{
	if (this->_value != rhs._value || this->_exponent != rhs._exponent)
		return true;
	else
		return false;
}

bool BigNumber::operator<(const BigNumber& rhs)
{
	//this < nb ?
	// tricky ex: -9.99E999999 < 0.00E00
	// tricky ex: 0.00E0 < -1E12
	if (this->_exponent == rhs._exponent)
	{
		return this->_value < rhs._value;
	}
	else if (this->_exponent < rhs._exponent)
	{
		if (std::copysign(1, rhs._value) == -1)
			return false;
		else
			return true;
	}
	else
	{
		if (std::copysign(1, this->_value) == -1)
			return true;
		else
			return false;
	}
}

bool BigNumber::operator<=(const BigNumber& rhs)
{
	//this <= nb ?
	// tricky ex: -9.99E999999 <= 0.00E00
	// tricky ex: 0.00E0 <= -1E12
	if (this->_exponent == rhs._exponent)
	{
		return this->_value <= rhs._value;
	}
	else if (this->_exponent <= rhs._exponent)
	{
		if (std::copysign(1, rhs._value) == -1)
			return false;
		else
			return true;
	}
	else
	{
		if (std::copysign(1, this->_value) == -1)
			return true;
		else
			return false;
	}
}

bool BigNumber::operator>(const BigNumber& rhs)
{
	//this > nb ?
		// tricky ex: -9.99E999999 > 0.00E00
	// tricky ex: 0.00E0 > -1E12
	if (this->_exponent == rhs._exponent)
	{
		return this->_value > rhs._value;
	}
	else if (this->_exponent > rhs._exponent)
	{
		if (std::copysign(1, this->_value) == -1)
			return false;
		else
			return true;
	}
	else
	{
		if (std::copysign(1, rhs._value) == -1)
			return true;
		else
			return false;
	}
}

bool BigNumber::operator>=(const BigNumber& rhs)
{
	//this >= nb ?
	if (this->_exponent == rhs._exponent)
	{
		return this->_value >= rhs._value;
	}
	else if (this->_exponent >= rhs._exponent)
	{
		if (std::copysign(1, this->_value) == -1)
			return false;
		else
			return true;
	}
	else
	{
		if (std::copysign(1, rhs._value) == -1)
			return true;
		else
			return false;
	}
}

BigNumber BigNumber::operator*(const BigNumber& rhs)
{
	//result = this * nb
	BigNumber result;
	result._value = this->_value * rhs._value;
	result._exponent = this->_exponent + rhs._exponent;

	while (result._value >= 10.0)
	{
		result._value /= 10;
		result._exponent++;
	}
	return result;
}

BigNumber BigNumber::operator/(const BigNumber& rhs)
{
	//result = this / nb
	BigNumber result;
	result._value = this->_value / rhs._value;
	result._exponent = this->_exponent - rhs._exponent;

	while (result._value >= 10.0)
	{
		result._value /= 10;
		result._exponent++;
	}
	return result;
}

void BigNumber::operator/=(const BigNumber& rhs)
{
	//this = this /= nb
	this->_value = this->_value / rhs._value;
	this->_exponent = this->_exponent - rhs._exponent;

	while (this->_value >= 10.0)
	{
		this->_value /= 10;
		this->_exponent++;
	}
	return;
}

void BigNumber::operator*=(const BigNumber& rhs)
{
	//this = this *= nb
	this->_value = this->_value * rhs._value;
	this->_exponent = this->_exponent + rhs._exponent;

	while (this->_value >= 10.0)
	{
		this->_value /= 10;
		this->_exponent++;
	}
	return;
}

BigNumber BigNumber::operator+(const BigNumber& rhs)
{
	//result = this + nb
	BigNumber result;
	float thisVal, nbVal;
	int thisExp, nbExp;
	thisExp = this->_exponent;
	thisVal = this->_value;
	nbExp = rhs._exponent;
	nbVal = rhs._value;

	//if difference in exponents is >= 3, return the largest nb
	if (this->_exponent >= rhs._exponent + 3)
	{
		result._exponent = this->_exponent;
		result._value = this->_value;
		return result;
	}
	else if (rhs._exponent >= this->_exponent + 3)
	{
		result._exponent = rhs._exponent;
		result._value = rhs._value;
		return result;
	}

	else //difference in exponents in 2 at most
	{
		if (this->_exponent > rhs._exponent)
		{
			while (thisExp != rhs._exponent) //make this and nb have the same exponent
			{
				thisVal *= 10;
				thisExp--;
			}
			result._value = thisVal + nbVal;
			result._exponent = rhs._exponent;
		}
		else if (rhs._exponent > this->_exponent)
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
			result._value = this->_value + rhs._value;
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

void BigNumber::operator+=(const BigNumber& rhs)
{
	//this = this + nb
	float thisVal, nbVal;
	int thisExp, nbExp;
	thisExp = this->_exponent;
	thisVal = this->_value;
	nbExp = rhs._exponent;
	nbVal = rhs._value;

	//if difference in exponents is >= 3, return the largest nb
	if (this->_exponent >= rhs._exponent + 3)
		return;
	else if (rhs._exponent >= this->_exponent + 3)
	{
		this->_exponent = rhs._exponent;
		this->_value = rhs._value;
		return;
	}
	else //difference in exponents in 2 at most
	{
		if (this->_exponent > rhs._exponent)
		{
			while (thisExp != rhs._exponent) //make this and nb have the same exponent
			{
				thisVal *= 10;
				thisExp--;
			}
			this->_value = thisVal + nbVal;
			this->_exponent = rhs._exponent;
		}
		else if (rhs._exponent > this->_exponent)
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
			this->_value = this->_value + rhs._value;
		}
	}
	while (this->_value >= 10.0)
	{
		this->_value /= 10;
		this->_exponent++;
	}
	return;
}

void BigNumber::operator-=(const BigNumber& rhs)
{
	//this = this - nb
	float thisVal, nbVal;
	int thisExp, nbExp;
	thisExp = this->_exponent;
	thisVal = this->_value;
	nbExp = rhs._exponent;
	nbVal = rhs._value;

	//if difference in exponents is >= 3, return the largest nb
	if (this->_exponent >= rhs._exponent + 3)
		return;
	else if (rhs._exponent >= this->_exponent + 3)
	{
		this->_exponent = rhs._exponent;
		this->_value = rhs._value;
		return;
	}

	else //difference in exponents in 2 at most
	{
		if (this->_exponent > rhs._exponent)
		{
			while (thisExp != rhs._exponent) //make this and nb have the same exponent
			{
				thisVal *= 10;
				thisExp--;
			}
			this->_value = thisVal - nbVal;
			this->_exponent = rhs._exponent;
		}
		else if (rhs._exponent > this->_exponent)
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
			this->_value = this->_value - rhs._value;
		}
	}
	while (this->_value >= 10.0)
	{
		this->_value /= 10;
		this->_exponent++;
	}
	return;
}

BigNumber BigNumber::operator-(const BigNumber& rhs)
{
	//TODO FIX this
	//result = this - nb
	BigNumber result;
	float thisVal, nbVal;
	int thisExp, nbExp;
	thisExp = this->_exponent;
	thisVal = this->_value;
	nbExp = rhs._exponent;
	nbVal = rhs._value;

	//if difference in exponents is >= 3, return the largest nb
	if (this->_exponent >= rhs._exponent + 3)
	{
		result._exponent = this->_exponent;
		result._value = this->_value;
		return result;
	}
	else if (rhs._exponent >= this->_exponent + 3)
	{
		result._exponent = rhs._exponent;
		result._value = -rhs._value;
		return result;
	}

	else //difference in exponents in 2 at most
	{
		if (this->_exponent > rhs._exponent)
		{
			while (thisExp != rhs._exponent) //make this and nb have the same exponent
			{
				thisVal *= 10;
				thisExp--;
			}
			result._value = thisVal - nbVal;
			result._exponent = rhs._exponent;
		}
		else if (rhs._exponent > this->_exponent)
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
			result._value = this->_value - rhs._value;
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

std::string BigNumber::asString(bool rounded)
{
	//TODO FIX ?
	//rounding happening here --> loss of precision
	//ex: _value 1.997... will be rounded to "2.00"
	std::stringstream streamVal, streamExp;
	if (this->_exponent <= 3)
	{
		return std::to_string(this->asInt());
	}
	else
	{
		if (rounded)
		{
			streamVal << std::fixed << std::setprecision(2) << _value;
			streamExp << std::fixed << std::setprecision(2) << _exponent;
		}
		else
		{
			streamVal << std::fixed << _value;
			streamExp << std::fixed << _exponent;
		}
		return streamVal.str() + "E" + streamExp.str();
	}
}

double BigNumber::to_double(const BigNumber& nb)
{
	//TODO could overflow easily if BigNumber is too big for a double
	double result = nb._value;
	int exponent = nb._exponent;
	while (exponent != 0)
	{
		result *= 10;
		exponent--;
	}
	return result;
}

int BigNumber::to_int(const BigNumber& nb)
{
	//TODO could overflow easily if BigNumber is too big for a double
	int result = nb._value;
	int exponent = nb._exponent;
	while (exponent != 0)
	{
		result *= 10;
		exponent--;
	}
	return result;
}

int BigNumber::asInt()
{
	//TODO could overflow easily if BigNumber is too big for a double
	int result = _value;
	int exponent = _exponent;
	while (exponent != 0)
	{
		result *= 10;
		exponent--;
	}
	return result;
}