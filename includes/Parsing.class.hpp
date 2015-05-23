#ifndef PARSING_HPP
# define PARSING_HPP

# include <fstream>
# include <iostream>
# include <vector>
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

	bool	checkCmd1(std::string const &line);
	bool	checkCmd2(std::string const &line);
	void	fileParsing(const char *av);
	void	stdoutParsing(void);

private:
	std::vector<std::string>			_cmds;
	std::map<std::string, operation1>	_op1;
	std::map<std::string, operation2>	_op2;
	//std::vector<IOperand const *>		_container;

};

#endif