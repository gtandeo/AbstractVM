#include "Factory.class.hpp"

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const
{
	return (this->*_tab[type])(value);
}

IOperand const * Factory::createInt8(std::string const &value) const
{
	Operand		*ret;

	if (std::atoi(value.c_str()) > INT8_MAX || std::atoi(value.c_str()) < INT8_MIN)
		throw std::exception();
	ret = new Operand(value, INT8);
	return ret;
}

IOperand const * Factory::createInt16(std::string const &value) const
{
	Operand		*ret;

	if (std::atoi(value.c_str()) > INT16_MAX || std::atoi(value.c_str()) < INT16_MIN)
		throw std::exception();
	ret = new Operand(value, INT16);
	return ret;
}

IOperand const * Factory::createInt32(std::string const &value) const
{
	Operand		*ret;

	if (std::atoi(value.c_str()) > INT32_MAX || std::atoi(value.c_str()) < INT32_MIN)
		throw std::exception();
	ret = new Operand(value, INT32);
	return ret;
}

IOperand const * Factory::createFloat(std::string const &value) const
{
	Operand		*ret;

	if (std::atoi(value.c_str()) > std::numeric_limits<float>::max() || std::atoi(value.c_str()) < std::numeric_limits<float>::min())
		throw std::exception();
	ret = new Operand(value, FLOAT);
	return ret;
}

IOperand const * Factory::createDouble(std::string const &value) const
{
	Operand		*ret;

	if (std::atoi(value.c_str()) > std::numeric_limits<double>::max() || std::atoi(value.c_str()) < std::numeric_limits<double>::min())
		throw std::exception();
	ret = new Operand(value, DOUBLE);
	return ret;
}
