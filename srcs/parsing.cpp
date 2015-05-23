#include "Parsing.class.hpp"

Parsing::UnknownException::UnknownException(void)
{
	return ;
}

Parsing::UnknownException::UnknownException(UnknownException const &src)
{
	*this = src;
	return ;
}

Parsing::UnknownException::~UnknownException(void) throw()
{
	return ;
}

const char	*Parsing::Parsing::UnknownException::what() const throw()
{
	return "std::exception: Unknown command";
};

Parsing::LessThatTwoValuesException::LessThatTwoValuesException(void)
{
	return ;
}

Parsing::LessThatTwoValuesException::LessThatTwoValuesException(LessThatTwoValuesException const &src)
{
	*this = src;
	return ;
}

Parsing::LessThatTwoValuesException::~LessThatTwoValuesException(void) throw()
{
	return ;
}

const char	*Parsing::Parsing::LessThatTwoValuesException::what() const throw()
{
	return "std::exception: stack is composed of less that two values";
};

Parsing::PopOnAnEmptyStackException::PopOnAnEmptyStackException(void)
{
	return ;
}

Parsing::PopOnAnEmptyStackException::PopOnAnEmptyStackException(PopOnAnEmptyStackException const &src)
{
	*this = src;
	return ;
}

Parsing::PopOnAnEmptyStackException::~PopOnAnEmptyStackException(void) throw()
{
	return ;
}

const char	*Parsing::Parsing::PopOnAnEmptyStackException::what() const throw()
{
	return "std::exception: pop on an empty stack";
};

Parsing::AssertException::AssertException(void)
{
	return ;
}

Parsing::AssertException::AssertException(AssertException const &src)
{
	*this = src;
	return ;
}

Parsing::AssertException::~AssertException(void) throw()
{
	return ;
}

const char	*Parsing::Parsing::AssertException::what() const throw()
{
	return "std::exception: assert instruction is not true";
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
	_cmds.push_back("exit");
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
		std::cout << tmp.top()->toString() << std::endl;
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
	result = *tmp / *_container.top();
	_container.pop();
	_container.push(f.createOperand(result->getType(), result->toString()));
	delete result;
}

void	Parsing::mod(void)
{
	/*Factory			f;
	IOperand const	*tmp;
	IOperand const	*result;

	if (_container.size() < 2)
		throw Parsing::LessThatTwoValuesException();
	tmp = _container.top();
	_container.pop();
	result = *tmp % *_container.top();
	_container.pop();
	_container.push(f.createOperand(result->getType(), result->toString()));
	delete result;*/
}

void	Parsing::print(void)
{
	std::stringstream	ss;
	int					ret;

	if (_container.size() && _container.top()->getType() == INT8)
	{
		ss << _container.top()->toString();
		ss >> ret;
		std::cout << static_cast<char>(ret) << std::endl;
		return ;
	}
	throw Parsing::AssertException();
}

bool	Parsing::checkCmd(std::string const &line)
{
	std::regex		r1("^[\\s]*(push|assert)[\\s]+(int8|int16|int32)[\\s]*\\(([-]?[0-9]+)\\)[\\s]*$", std::regex_constants::icase);
	std::regex		r2("^[\\s]*(push|assert)[\\s]+(float|double)[\\s]*\\([-]?[0-9]+(?:\\.[0-9]+)?\\)[\\s]*$", std::regex_constants::icase);
	std::regex		r3("^[\\s]*(pop|dump|add|sub|mul|div|mod|print)[\\s]*$", std::regex_constants::icase);
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
	else if (line == "exit")
		return true;
	throw Parsing::UnknownException();
}

void	Parsing::execCmd(void)
{
	for (std::vector<std::string>::iterator it = _inputs.begin(); it != _inputs.end(); it++)
	{
		try {
			checkCmd(*it);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
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
	this->_op2["push"] = &Parsing::push;
	this->_op2["assert"] = &Parsing::assert;
}

void	Parsing::fileParsing(const char *av)
{
	std::ifstream	file(av);
	std::string		line;

	initPtr();
	while (std::getline(file, line) && line != "exit")
		_inputs.push_back(line);
	execCmd();
	return ;
}

void	Parsing::stdoutParsing(void)
{
	std::string		line;

	initPtr();
	while (line != "exit" && !std::cin.eof())
	{
		std::getline(std::cin, line);
		_inputs.push_back(line);
	}
	while (std::getline(std::cin, line) && line != "#");
	execCmd();
	return ;
}