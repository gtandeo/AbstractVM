#ifndef PARSING_HPP
# define PARSING_HPP

# include <fstream>
# include <iostream>
# include <list>
# include <map>
# include <regex>
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
	void	print(void);
	
	bool	checkCmd1(std::string const &line);
	bool	checkCmd2(std::string const &line);
	void	fileParsing(const char *av);
	void	stdoutParsing(void);

private:
	std::vector<std::string>			_cmds;
	std::map<std::string, operation1>	_op1;
	std::map<std::string, operation2>	_op2;
	std::list<IOperand const *>		_container;

};

#endif