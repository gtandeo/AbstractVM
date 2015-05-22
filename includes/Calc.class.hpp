#ifndef CALC_CLASS_HPP
# define CALC_CLASS_HPP

# include "IOperand.class.hpp"
# include "Operand.class.hpp" 

class Calc : public IOperand {

typedef IOperand const *(Operand::*fctPtr)(std::string const &value) const;

public:
	Calc(void) {}
	Calc(Calc const &src) {*this = src;}
	~Calc(void) {}

	IOperand const	*createOperand(eOperandType type, std::string const &value) const;

private:

};

#endif