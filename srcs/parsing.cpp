#include "Parsing.class.hpp"

const char	*Parsing::Parsing::UnknownException::what() const throw()
{
	return "std::exception: Unknown command";
};

const char	*Parsing::Parsing::LessThatTwoValuesException::what() const throw()
{
	return "std::exception: stack is composed of less that two values";
};

const char	*Parsing::Parsing::PopOnAnEmptyStackException::what() const throw()
{
	return "std::exception: pop on an empty stack";
};

const char	*Parsing::Parsing::AssertException::what() const throw()
{
	return "std::exception: assert instruction is not true";
};

const char	*Parsing::Parsing::DivModException::what() const throw()
{
	return "std::exception: division/modulo by 0";
};

const char	*Parsing::Parsing::ExitException::what() const throw()
{
	return "std::exception: program doesn’t have an exit instruction";
};

Parsing::Parsing(void)
{
	_cmds.push_back("push");
	_cmds.push_back("pop");
	_cmds.push_back("dump");
	_cmds.push_back("assert");
	_cmds.push_back("add");
	_cmds.push_back("sub");
	_cmds.push_back("mul");
	_cmds.push_back("div");
	_cmds.push_back("mod");
	_cmds.push_back("print");
	_cmds.push_back("cat");
}

void	Parsing::push(IOperand const *data)
{
	_container.push(data);
	return ;
}

void	Parsing::assert(IOperand const *data)
{
	if (data->toString() != _container.top()->toString() || data->getType() != _container.top()->getType())
		throw Parsing::AssertException();
}

void	Parsing::pop(void)
{
	if (!_container.size())
		throw Parsing::PopOnAnEmptyStackException();
	_container.pop();
	return ;
}

void	Parsing::dump(void)
{
	std::stack<IOperand const *>	tmp;

	tmp = _container;
	while (tmp.size())
	{
		std::cout << "\033[4;33m" << tmp.top()->toString() << "\033[0m" << std::endl;
		tmp.pop();
	}
}

void	Parsing::add(void)
{
	Factory			f;
	IOperand const	*tmp;
	IOperand const	*result;

	if (_container.size() < 2)
		throw Parsing::LessThatTwoValuesException();
	tmp = _container.top();
	_container.pop();
	result = *tmp + *_container.top();
	_container.pop();
	_container.push(f.createOperand(result->getType(), result->toString()));
	delete result;
}

void	Parsing::sub(void)
{
	Factory			f;
	IOperand const	*tmp;
	IOperand const	*result;

	if (_container.size() < 2)
		throw Parsing::LessThatTwoValuesException();
	tmp = _container.top();
	_container.pop();
	result = *tmp - *_container.top();
	_container.pop();
	_container.push(f.createOperand(result->getType(), result->toString()));
	delete result;
}

void	Parsing::mul(void)
{
	Factory			f;
	IOperand const	*tmp;
	IOperand const	*result;

	if (_container.size() < 2)
		throw Parsing::LessThatTwoValuesException();
	tmp = _container.top();
	_container.pop();
	result = *tmp * *_container.top();
	_container.pop();
	_container.push(f.createOperand(result->getType(), result->toString()));
	delete result;
}

void	Parsing::div(void)
{
	Factory			f;
	IOperand const	*tmp;
	IOperand const	*result;

	if (_container.size() < 2)
		throw Parsing::LessThatTwoValuesException();
	tmp = _container.top();
	_container.pop();
	if (_container.top()->toString() == "0")
	{
		_container.push(tmp);
		throw Parsing::DivModException();
	}
	result = *tmp / *_container.top();
	_container.pop();
	_container.push(f.createOperand(result->getType(), result->toString()));
	delete result;
}

void	Parsing::mod(void)
{
	Factory				f;
	IOperand const		*tmp;
	IOperand const		*result;

	if (_container.size() < 2)
		throw Parsing::LessThatTwoValuesException();
	tmp = _container.top();
	_container.pop();
	if (_container.top()->toString() == "0")
	{
		_container.push(tmp);
		throw Parsing::DivModException();
	}
	result = *tmp % *_container.top();
	_container.pop();
	_container.push(f.createOperand(result->getType(), result->toString()));
}

void	Parsing::print(void)
{
	std::stringstream	ss;
	int					ret;

	if (_container.size() && _container.top()->getType() == INT8)
	{
		ss << _container.top()->toString();
		ss >> ret;
		std::cout << "\033[1;34m" << static_cast<char>(ret) << "\033[0m" << std::endl;
		return ;
	}
	throw Parsing::AssertException();
}

void	Parsing::cat(void)																								                        
{
	std::stringstream ss;

	ss << "  _" << std::endl << "  \\`*-. " << std::endl \
		<< "   )  _`-.  " << std::endl \
		<< "  .  : `. .  " << std::endl \
		<< "  : _   '  \\  " << std::endl \
		<< "  ; *` _.   `*-._   " << std::endl \
		<< "  `-.-'          `-.  " << std::endl \
		<< "    ;       `       `.    " << std::endl \
		<< "    :.       .        \\  " << std::endl \
		<< "    . \\  .   :   .-'   . " << std::endl \
		<< "    '  `+.;  ;  '      : " << std::endl \
		<< "    :  '  |    ;       ;-. " << std::endl \
		<< "    ; '   : :`-:     _.`* ;" << std::endl \
		<< " .*' /  .*' ; .*`- +'  `*' " << std::endl \
		<< " `*-*   `*-*  `*-*'        " << std::endl;
	std::cout << ss.str();
	return ;
}

bool	Parsing::checkCmd(std::string const &line, int val)
{
	std::regex		r1("^[\\s]*(push|assert)[\\s]+(int8|int16|int32)[\\s]*\\(([-]?[0-9]+)\\)[\\s]*$", std::regex_constants::icase);
	std::regex		r2("^[\\s]*(push|assert)[\\s]+(float|double)[\\s]*\\(([-]?([0-9]+(?:[.][0-9]+)?))\\)[\\s]*$", std::regex_constants::icase);
	std::regex		r3("^[\\s]*(pop|dump|add|sub|mul|div|mod|print|cat)[\\s]*$", std::regex_constants::icase);
	std::smatch		m;
	std::smatch		m2;
	std::smatch		m3;
	Factory			f;

	if (regex_search(line, m, r1))
	{
		std::string		cmd = m[1].str();
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
		std::string		type = m[2].str();
		std::transform(type.begin(), type.end(), type.begin(), ::tolower);
		if (m[2] == "int8")
			(this->*_op2[m[1]])(f.createOperand(INT8, m[3].str()));
		else if (m[2] == "int16")
			(this->*_op2[m[1]])(f.createOperand(INT16, m[3].str()));
		else if (m[2] == "int32")
			(this->*_op2[m[1]])(f.createOperand(INT32, m[3].str()));
		else if (m[2] == "float")
			(this->*_op2[m[1]])(f.createOperand(FLOAT, m[3].str()));
		else if (m[2] == "double")
			(this->*_op2[m[1]])(f.createOperand(DOUBLE, m[3].str()));
		return true;
	}
	else if (regex_search(line, m2, r2))
	{
		std::string		cmd = m2[1].str();
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
		std::string		type = m2[2].str();
		std::transform(type.begin(), type.end(), type.begin(), ::tolower);
		if (m2[2] == "int8")
			(this->*_op2[m2[1]])(f.createOperand(INT8, m2[3].str()));
		else if (m2[2] == "int16")
			(this->*_op2[m2[1]])(f.createOperand(INT16, m2[3].str()));
		else if (m2[2] == "int32")
			(this->*_op2[m2[1]])(f.createOperand(INT32, m2[3].str()));
		else if (m2[2] == "float")
			(this->*_op2[m2[1]])(f.createOperand(FLOAT, m2[3].str()));
		else if (m2[2] == "double")
			(this->*_op2[m2[1]])(f.createOperand(DOUBLE, m2[3].str()));
		return true;
	}
	else if (regex_search(line, m3, r3))
	{
		std::string		cmd = m3[1].str();
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
		(this->*_op1[m3[1]])();
		return true;
	}
	else if (val == 0 && line == "exit")
		return true;
	throw Parsing::UnknownException();
}

void	Parsing::execCmd(int val)
{
	for (std::vector<std::string>::iterator it = _inputs.begin(); it != _inputs.end(); it++)
	{
		try {
			checkCmd(*it, val);
		}
		catch (std::exception &e) {
			std::cout << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
		}
	}
}

void	Parsing::initPtr(void)
{
	this->_op1["pop"] = &Parsing::pop;
	this->_op1["dump"] = &Parsing::dump;
	this->_op1["add"] = &Parsing::add;
	this->_op1["sub"] = &Parsing::sub;
	this->_op1["mul"] = &Parsing::mul;
	this->_op1["div"] = &Parsing::div;
	this->_op1["mod"] = &Parsing::mod;
	this->_op1["print"] = &Parsing::print;
	this->_op1["cat"] = &Parsing::cat;
	this->_op2["push"] = &Parsing::push;
	this->_op2["assert"] = &Parsing::assert;
}

void	Parsing::fileParsing(const char *av)
{
	std::ifstream	file(av);
	std::string		line;

	initPtr();
	while (std::getline(file, line) && line != "exit")
	{
		if (line[0] != ';' && line.size())
			_inputs.push_back(line);
	}
	execCmd(0);
	if (line != "exit")
		throw Parsing::ExitException();
	return ;
}

void	Parsing::stdoutParsing(void)
{
	std::string		line;

	initPtr();
	while (line != ";;" && !std::cin.eof())
	{
		std::getline(std::cin, line);
		if (line[0] != ';' && line.size())
			_inputs.push_back(line);
	}
	execCmd(1);
	return ;
}