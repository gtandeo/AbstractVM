#include "Operand.class.hpp"

Operand::Operand(void)
{
	return ;
}

Operand::Operand(Operand const &src)
{
	*this = src;
	return ;
}

Operand::Operand(std::string const &value) : _value(value)
{
	return ;
}

Operand::~Operand(void)
{
	return ;
}

IOperand const * Operand::createOperand(eOperandType type, std::string const &value) const
{
	return tab[type](value);
}

IOperand const * Operand::createInt8(std::string const &value) const
{
	return new Operand(value);
}

IOperand const * Operand::createInt16(std::string const &value) const
{
	;
}

IOperand const * Operand::createInt32(std::string const &value) const
{
	;
}

IOperand const * Operand::createFloat(std::string const &value) const
{
	;
}

IOperand const * Operand::createDouble(std::string const &value) const
{
	;
}
