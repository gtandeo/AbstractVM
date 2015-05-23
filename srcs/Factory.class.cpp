#include "Factory.class.hpp"

Factory::OverFlowException::OverFlowException(void)
{
	return ;
}

Factory::OverFlowException::OverFlowException(OverFlowException const &src)
{
	*this = src;
	return ;
}

Factory::OverFlowException::~OverFlowException(void) throw()
{
	return ;
}

const char	*Factory::Factory::OverFlowException::what() const throw()
{
	return "std::exception: overflow on a value";
};

Factory::UnderFlowException::UnderFlowException(void)
{
	return ;
}

Factory::UnderFlowException::UnderFlowException(UnderFlowException const &src)
{
	*this = src;
	return ;
}

Factory::UnderFlowException::~UnderFlowException(void) throw()
{
	return ;
}

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

	if (std::atoi(value.c_str()) > INT32_MAX)
		throw Factory::OverFlowException();
	else if (std::atoi(value.c_str()) < INT32_MIN)
		throw Factory::UnderFlowException();
	ret = new Operand(value, INT32);
	return ret;
}

IOperand const * Factory::createFloat(std::string const &value) const
{
	Operand		*ret;

	if (std::atof(value.c_str()) > std::numeric_limits<float>::max())
		throw Factory::OverFlowException();
	else if (std::atof(value.c_str()) < std::numeric_limits<float>::min())
		throw Factory::UnderFlowException();
	ret = new Operand(value, FLOAT);
	return ret;
}

IOperand const * Factory::createDouble(std::string const &value) const
{
	Operand		*ret;

	if (std::stod(value.c_str()) > std::numeric_limits<double>::max())
		throw Factory::OverFlowException();
	else if (std::stod(value.c_str()) < std::numeric_limits<double>::min())
		throw Factory::UnderFlowException();
	ret = new Operand(value, DOUBLE);
	return ret;
}
