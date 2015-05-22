#include "Operand.class.hpp"

Operand::Operand(std::string const &value, eOperandType type) : _value(value), _type(type)
{
	_tab[0] = &Operand::createInt8;
	_tab[1] = &Operand::createInt16;
	_tab[2] = &Operand::createInt32;
	_tab[3] = &Operand::createFloat;
	_tab[4] = &Operand::createDouble;
	return ;
}

/*IOperand const * operator+(IOperand const &rhs) const
{

}

IOperand const * operator-(IOperand const &rhs) const
{

}

IOperand const * operator*(IOperand const &rhs) const
{

}

IOperand const * operator/(IOperand const &rhs) const
{

}

IOperand const * operator%(IOperand const &rhs) const
{

}*/

IOperand const * Operand::createOperand(eOperandType type, std::string const &value) const
{
	return (this->*_tab[type])(value);
}

IOperand const * Operand::createInt8(std::string const &value) const
{
	Operand		*ret;

	ret = new Operand(value, INT8);
	return ret;
}

IOperand const * Operand::createInt16(std::string const &value) const
{
	Operand		*ret;

	ret = new Operand(value, INT16);
	return ret;
}

IOperand const * Operand::createInt32(std::string const &value) const
{
	Operand		*ret;

	ret = new Operand(value, INT32);
	return ret;
}

IOperand const * Operand::createFloat(std::string const &value) const
{
	Operand		*ret;

	ret = new Operand(value, FLOAT);
	return ret;
}

IOperand const * Operand::createDouble(std::string const &value) const
{
	Operand		*ret;

	ret = new Operand(value, DOUBLE);
	return ret;
}
