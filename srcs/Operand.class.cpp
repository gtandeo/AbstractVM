#include "Operand.class.hpp"

Operand::Operand(std::string const &value, eOperandType type) : _value(value), _type(type)
{
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

IOperand const * Operand::createInt8(std::string const &value) const
{
	Operand		*ret;

	if (std::atoi(value.c_str()) > INT8_MAX || std::atoi(value.c_str()) < INT8_MIN)
		throw std::exception();
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
