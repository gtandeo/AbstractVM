#include "Calc.class.hpp"

IOperand const * Calc::createOperand(eOperandType type, std::string const &value) const
{
	return (this->*_tab[type])(value);
}