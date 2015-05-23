#include "Operand.class.hpp"

Operand::Operand(std::string const &value, eOperandType type) : _value(value), _type(type)
{
	return ;
}

eOperandType	Operand::getType(void) const
{
	return _type;
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

std::string const &Operand::toString(void) const
{
	return _value;
}
