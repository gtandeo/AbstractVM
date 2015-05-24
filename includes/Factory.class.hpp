#ifndef FACTORY_CLASS_HPP
# define FACTORY_CLASS_HPP

# include "Operand.class.hpp"

class Factory {

typedef IOperand const *(Factory::*fctPtr)(std::string const &value) const;

public:
	Factory(void) {}
	Factory(Factory const &src) {*this = src;}
	~Factory(void) {}

	IOperand const * createOperand( eOperandType type, std::string const & value ) const;

	class OverFlowException : public std::exception {
		public:
			OverFlowException(void) {}
			OverFlowException(OverFlowException const &src) {*this = src;}
			~OverFlowException(void) throw() {}

			const char	*what() const throw();
	};

	class UnderFlowException : public std::exception {
		public:
			UnderFlowException(void) {}
			UnderFlowException(UnderFlowException const &src) {*this = src;}
			~UnderFlowException(void) throw() {}

			const char	*what() const throw();
	};

private:
	fctPtr	_tab[5] = {
		&Factory::createInt8,
		&Factory::createInt16,
		&Factory::createInt32,
		&Factory::createFloat,
		&Factory::createDouble
	};
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;

};

#endif