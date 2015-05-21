#ifndef OPERAND_CLASS_HPP
# define OPERAND_CLASS_HPP

# include "IOperand.class.hpp"

typedef IOperand const *(*fctPtr)(std::string const &value) const;

class Operand : public IOperand {

public:
	Operand(void) {}
	Operand(Operand const &src) {*this = src}
	~Operand(void) {}

	IOperand const * createOperand(eOperandType type, std::string const &value) const;

private:
	IOperand const * createInt8(std::string const &value) const;
	IOperand const * createInt16(std::string const &value) const;
	IOperand const * createInt32(std::string const &value) const;
	IOperand const * createFloat(std::string const &value) const;
	IOperand const * createDouble(std::string const &value) const;

};

#endif