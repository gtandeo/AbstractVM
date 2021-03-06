#include "Operand.class.hpp"

Operand::Operand(std::string const &value, eOperandType type) : _value(value), _type(type)
{
	return ;
}

int				Operand::getPrecision(void) const
{
	return _type;
}

eOperandType	Operand::getType(void) const
{
	return _type;
}

IOperand const * Operand::operator+(IOperand const &rhs) const
{
	Factory			f;
	eOperandType	e;
	std::stringstream	ss;

	this->getType() >= rhs.getType() ? e = this->getType() : e = rhs.getType();
	ss << std::stod(this->toString().c_str()) + std::stod(rhs.toString().c_str());
	IOperand const *ret = f.createOperand(e, ss.str());
	return ret;
}

IOperand const * Operand::operator-(IOperand const &rhs) const
{
	Factory			f;
	eOperandType	e;
	std::stringstream	ss;

	this->getType() >= rhs.getType() ? e = this->getType() : e = rhs.getType();
	ss << std::stod(this->toString().c_str()) - std::stod(rhs.toString().c_str());
	IOperand const *ret = f.createOperand(e, ss.str());
	return ret;
}

IOperand const * Operand::operator*(IOperand const &rhs) const
{
	Factory			f;
	eOperandType	e;
	std::stringstream	ss;

	this->getType() >= rhs.getType() ? e = this->getType() : e = rhs.getType();
	ss << std::stod(this->toString().c_str()) * std::stod(rhs.toString().c_str());
	IOperand const *ret = f.createOperand(e, ss.str());
	return ret;
}

IOperand const * Operand::operator/(IOperand const &rhs) const
{
	Factory			f;
	eOperandType	e;
	std::stringstream	ss;

	this->getType() >= rhs.getType() ? e = this->getType() : e = rhs.getType();
	ss << std::stod(this->toString().c_str()) / std::stod(rhs.toString().c_str());
	IOperand const *ret = f.createOperand(e, ss.str());
	return ret;
}

IOperand const * Operand::operator%(IOperand const &rhs) const
{
	Factory			f;
	eOperandType	e;
	std::stringstream	ss;

	this->getType() >= rhs.getType() ? e = this->getType() : e = rhs.getType();
	ss << std::fmod(std::stod(this->toString().c_str()), std::stod(rhs.toString().c_str()));
	IOperand const *ret = f.createOperand(e, ss.str());
	return ret;
}

std::string const &Operand::toString(void) const
{
	return _value;
}
