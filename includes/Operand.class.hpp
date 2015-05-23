#ifndef OPERAND_CLASS_HPP
# define OPERAND_CLASS_HPP

# include <stdlib.h>
# include <sstream>
# include "IOperand.class.hpp"
# include "Factory.class.hpp"

class Operand : public IOperand {

typedef IOperand const *(Operand::*fctPtr)(std::string const &value) const;

public:
	Operand(void) {}
	Operand(Operand const &src) {*this = src;}
	Operand(std::string const &value, eOperandType type);
	~Operand(void) {}

private:
	std::string		_value;
	eOperandType	_type;
	//int getPrecision(void) const; // Precision of the type of the instance
	eOperandType getType(void) const; // Type of the instance

	IOperand const * operator+(IOperand const &rhs) const; // Sum
	//IOperand const * operator-(IOperand const &rhs) const; // Difference
	//IOperand const * operator*(IOperand const &rhs) const; // Product
	//IOperand const * operator/(IOperand const &rhs) const; // Quotient
	//IOperand const * operator%(IOperand const &rhs) const; // Modulo

	std::string const &toString(void) const; // String representation of the instance

};

#endif
