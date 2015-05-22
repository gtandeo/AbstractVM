#ifndef OPERAND_CLASS_HPP
# define OPERAND_CLASS_HPP

# include "IOperand.class.hpp"

class Operand : public IOperand {

typedef IOperand const *(Operand::*fctPtr)(std::string const &value) const;

public:
	Operand(void) {}
	Operand(Operand const &src) {*this = src;}
	Operand(std::string const &value, eOperandType type);
	~Operand(void) {}

	IOperand const * createOperand(eOperandType type, std::string const &value) const;

private:
	fctPtr			_tab[5];
	std::string		_value;
	eOperandType	_type;

	IOperand const * createInt8(std::string const &value) const;
	IOperand const * createInt16(std::string const &value) const;
	IOperand const * createInt32(std::string const &value) const;
	IOperand const * createFloat(std::string const &value) const;
	IOperand const * createDouble(std::string const &value) const;

};

#endif