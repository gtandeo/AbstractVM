#include "Operand.class.hpp"

IOperand const * Operand::createOperand(eOperandType type, std::string const &value) const
{
	return tab[type](value);
}

IOperand const * Operand::createInt8(std::string const &value) const
{
	Operand		*ret;

	ret = new Operand(value);
	_type = INT8;
	return ret;
}

IOperand const * Operand::createInt16(std::string const &value) const
{
	Operand		*ret;

	ret = new Operand(value);
	_type = INT16;
	return ret;
}

IOperand const * Operand::createInt32(std::string const &value) const
{
	Operand		*ret;

	ret = new Operand(value);
	_type = INT32;
	return ret;
}

IOperand const * Operand::createFloat(std::string const &value) const
{
	Operand		*ret;

	ret = new Operand(value);
	_type = FLOAT;
	return ret;
}

IOperand const * Operand::createDouble(std::string const &value) const
{
	Operand		*ret;

	//if (value > sizeof(double))
	//	throw std::exception();
	ret = new Operand(value);
	_type = DOUBLE;
	return ret;
}
