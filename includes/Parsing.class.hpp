#ifndef PARSING_HPP
# define PARSING_HPP

# include <fstream>
# include <iostream>
# include <stack>
# include <map>
# include <regex>
# include <math.h>
# include "Operand.class.hpp"
# include "Factory.class.hpp"

class	Parsing {

typedef void (Parsing::*operation1)(void);
typedef void (Parsing::*operation2)(IOperand const *);

public:
	Parsing(void);
	Parsing(Parsing const &src) {*this = src;}
	~Parsing(void) {}

	void	push(IOperand const *data);
	void	assert(IOperand const *data);
	void	pop(void);
	void	dump(void);
	void	add(void);
	void	sub(void);
	void	mul(void);
	void	div(void);
	void	mod(void);
	void	sqrt(void);
	void	fact(void);
	void	print(void);
	void	cat(void);
	
	void	initPtr(void);
	void	execCmd(int val);
	bool	checkCmd(std::string const &line, int val);
	void	fileParsing(const char *av);
	void	stdoutParsing(void);

	class UnknownException : public std::exception {
		public:
			UnknownException(void) {}
			UnknownException(UnknownException const &src) {*this = src;}
			~UnknownException(void) throw() {}

			const char	*what() const throw();
	};

	class LessThatTwoValuesException : public std::exception {
		public:
			LessThatTwoValuesException(void) {}
			LessThatTwoValuesException(LessThatTwoValuesException const &src) {*this = src;}
			~LessThatTwoValuesException(void) throw() {}

			const char	*what() const throw();
	};

	class PopOnAnEmptyStackException : public std::exception {
		public:
			PopOnAnEmptyStackException(void) {}
			PopOnAnEmptyStackException(PopOnAnEmptyStackException const &src) {*this = src;}
			~PopOnAnEmptyStackException(void) throw() {}

			const char	*what() const throw();
	};

	class AssertException : public std::exception {
		public:
			AssertException(void) {}
			AssertException(AssertException const &src) {*this = src;}
			~AssertException(void) throw() {}

			const char	*what() const throw();
	};

	class DivModException : public std::exception {
		public:
			DivModException(void) {}
			DivModException(DivModException const &src) {*this = src;}
			~DivModException(void) throw() {}

			const char	*what() const throw();
	};

	class ExitException : public std::exception {
		public:
			ExitException(void) {}
			ExitException(ExitException const &src) {*this = src;}
			~ExitException(void) throw() {}

			const char	*what() const throw();
	};

	class FactException : public std::exception {
		public:
			FactException(void) {}
			FactException(FactException const &src) {*this = src;}
			~FactException(void) {}
			const char	*what() const throw();
	};

	class FactTypeException : public std::exception {
		public:
			FactTypeException(void) {}
			FactTypeException(FactTypeException const &src) {*this = src;}
			~FactTypeException(void) {}
			const char	*what() const throw();
	};

private:
	std::vector<std::string>			_cmds;
	std::vector<std::string>			_inputs;
	std::map<std::string, operation1>	_op1;
	std::map<std::string, operation2>	_op2;
	std::stack<IOperand const *>		_container;

};

#endif