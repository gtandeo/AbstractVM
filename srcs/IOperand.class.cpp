#include "IOperand.class.hpp"

IOperand::IOperand(void);
{
	return ;
}

IOperand::IOperand(std::string val, eOperandType type) : _value(val), _type(type)
{
	return ;
}

IOperand::IOperand(IOperand const &src);
{
	*this = src;
	return ;
}

virtual IOperand::~IOperand( void ) {}
{
	return ;
}

IOperand const * IOperand::createOperand( eOperandType type, std::string const & value ) const;
{
	return tab[type](value);
}

/*virtual int IOperand::getPrecision( void ) const = 0;
{
	;
}*/

virtual eOperandType IOperand::getType( void ) const = 0;
{
	return _type;
}

static eOperand		getMaxType(IOperand const *first, IOperand const &second)
{
	return first->getType() >= second->getType() ? first->getType(), second.getType();
}

virtual IOperand const * IOperand::operator+( IOperand const & rhs ) const = 0;
{
	eOperandType ot = getMaxType(this, rhs);

	if (atoi(_value) + atoi(rhs.getValue()) > sizeof(ot) || atoi(_value) + atoi(rhs.getValue()) < sizeof(ot) * -1)
		throw std::exception;
	return new IOperand(atoi(_value) + atoi(rhs.getValue(), ot);
}

virtual IOperand const * IOperand::operator-( IOperand const & rhs ) const = 0;
{
	eOperandType ot = getMaxType(this, rhs);

	if (atoi(_value) - atoi(rhs.getValue()) > sizeof(ot) || atoi(_value) - atoi(rhs.getValue()) < sizeof(ot) * -1)
		throw std::exception;
	return new IOperand(atoi(_value) - atoi(rhs.getValue(), ot);
}

virtual IOperand const * IOperand::operator*( IOperand const & rhs ) const = 0;
{
	eOperandType ot = getMaxType(this, rhs);

	if (atoi(_value) * atoi(rhs.getValue()) > sizeof(ot) || atoi(_value) * atoi(rhs.getValue()) < sizeof(ot) * -1)
		throw std::exception;
	return new IOperand(atoi(_value) * atoi(rhs.getValue(), ot);
}

virtual IOperand const * IOperand::operator/( IOperand const & rhs ) const = 0;
{
	if (!atoi(rhs.getValue()))
		throw std::exception;
	IOperand	*ret = new(IOperand(itoa(atoi(_value) / atoi(rhs.getValue()))));
	return ret;
}

virtual IOperand const * IOperand::operator%( IOperand const & rhs ) const = 0;
{
	if (!atoi(rhs.getValue()))
		throw std::exception;
	IOperand	*ret = new(IOperand(itoa(atoi(_value) % atoi(rhs.getValue()))));
	return ret;
}

/*virtual std::string const & IOperand::toString( void ) const = 0;
{
	;
}*/

IOperand const * IOperand::createInt8( std::string const & value ) const
{
	return new IOperand(_value, 0);
}

IOperand const * IOperand::createInt16( std::string const & value ) const
{
	return new IOperand(_value, 1);
}

IOperand const * IOperand::createInt32( std::string const & value ) const
{
	return new IOperand(_value, 2);
}

IOperand const * IOperand::createFloat( std::string const & value ) const
{
	return new IOperand(_value, 3);
}

IOperand const * IOperand::createDouble( std::string const & value ) const
{
	return new IOperand(_value, 4);
}
