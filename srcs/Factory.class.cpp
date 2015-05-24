#include "Factory.class.hpp"

const char	*Factory::Factory::OverFlowException::what() const throw()
{
	return "std::exception: overflow on a value";
};

const char	*Factory::Factory::UnderFlowException::what() const throw()
{
	return "std::exception: underflow on a value";
};

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const
{
	return (this->*_tab[type])(value);
}

IOperand const * Factory::createInt8(std::string const &value) const
{
	Operand		*ret;

	if (std::atoi(value.c_str()) > INT8_MAX)
		throw Factory::OverFlowException();
	else if (std::atoi(value.c_str()) < INT8_MIN)
		throw Factory::UnderFlowException();
	ret = new Operand(value, INT8);
	return ret;
}

IOperand const * Factory::createInt16(std::string const &value) const
{
	Operand		*ret;

	if (std::atoi(value.c_str()) > INT16_MAX)
		throw Factory::OverFlowException();
	else if (std::atoi(value.c_str()) < INT16_MIN)
		throw Factory::UnderFlowException();
	ret = new Operand(value, INT16);
	return ret;
}

IOperand const * Factory::createInt32(std::string const &value) const
{
	Operand		*ret;

	if (std::stod(value.c_str()) > INT32_MAX)
		throw Factory::OverFlowException();
	else if (std::stod(value.c_str()) < INT32_MIN)
		throw Factory::UnderFlowException();
	ret = new Operand(value, INT32);
	return ret;
}

IOperand const * Factory::createFloat(std::string const &value) const
{
	Operand		*ret;

	if (std::stod(value.c_str()) > FLT_MAX)
		throw Factory::OverFlowException();
	else if (std::stod(value.c_str()) < FLT_MAX * -1)
		throw Factory::UnderFlowException();
	ret = new Operand(value, FLOAT);
	return ret;
}

IOperand const * Factory::createDouble(std::string const &value) const
{
	Operand		*ret;

	if (std::stold(value.c_str()) > DBL_MAX)
		throw Factory::OverFlowException();
	else if (std::stold(value.c_str()) < DBL_MAX * -1)
		throw Factory::UnderFlowException();
	ret = new Operand(value, DOUBLE);
	return ret;
}
