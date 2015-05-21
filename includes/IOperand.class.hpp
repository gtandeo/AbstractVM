#ifndef IOPERAND_CLASS_HPP
# define IOPERAND_CLASS_HPP

# include <stdlib.h>
# include <cstdlib>
# include <iostream>

class IOperand {

public:
	IOperand(void){}
	IOperand(IOperand const &src) {*this=src;}

	virtual intgetPrecision(void) const = 0; // Precision of the type of the instance
	virtual eOperandTypegetType(void) const = 0; // Type of the instance

	virtual IOperandconst * operator+(IOperand const &rhs) const = 0; // Sum
	virtual IOperandconst * operator-(IOperand const &rhs) const = 0; // Difference
	virtual IOperandconst * operator*(IOperand const &rhs) const = 0; // Product
	virtual IOperandconst * operator/(IOperand const &rhs) const = 0; // Quotient
	virtual IOperandconst * operator%(IOperand const &rhs) const = 0; // Modulo

	virtual std::string const &toString(void) const = 0; // String representation of the instance

	virtual~IOperand(void){}

};

#endif