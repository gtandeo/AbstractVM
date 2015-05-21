#ifndef IOPERAND_CLASS_HPP
# define IOPERAND_CLASS_HPP

# include <stdlib.h>
# include <cstdlib>
# include <iostream>

typedef enum eOperandType
{
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE
} eOperandType;

class IOperand {

typedef IOperand const *(IOperand::*fct)(const std::string &) const;

public:
	IOperand(void);
	IOperand(IOperand const &src);
	virtual ~IOperand( void ) {}
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	
	//virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
	virtual eOperandType getType( void ) const = 0; // Type of the instance
	virtual std::string getValue( void ) const = 0; // Value of the instance

	virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
	virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
	virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
	virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
	virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo

private:
	eOperandType		_type;
	std::string			_value;

	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;
	static const fct	constexpr tab[5] = {&IOperand::createInt8, &IOperand::createInt16, &IOperand::createInt32, &IOperand::createFloat, &IOperand::createDouble};
};

#endif