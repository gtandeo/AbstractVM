#include "Parsing.class.hpp"

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
	(void)data;
}

void	Parsing::pop(void)
{
	if (!_container.size())
		throw std::exception();
	_container.pop();
	return ;
}

void	Parsing::dump(void)
{
	;
}

void	Parsing::add(void)
{
	Factory			f;
	IOperand const	*tmp;
	IOperand const	*result;

	if (_container.size() < 2)
		throw std::exception();
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
		throw std::exception();
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
		throw std::exception();
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
		throw std::exception();
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
		throw std::exception();
	tmp = _container.top();
	_container.pop();
	result = *tmp % *_container.top();
	_container.pop();
	_container.push(f.createOperand(result->getType(), result->toString()));
	delete result;*/
}

void	Parsing::print(void)
{
	std::stack<IOperand const *>	tmp;

	tmp = _container;
	while (tmp.size())
	{
		std::cout << tmp.top()->toString() << std::endl;
		tmp.pop();
	}
}

bool	Parsing::checkCmd1(std::string const &line)
{
	std::regex		r1("^[\\s]*(push|assert)[\\s]+(int8|int16|int32)[\\s]*\\(([-]?[0-9]+)\\)$", std::regex_constants::icase);
	std::regex		r2("^[\\s]*(push|assert)[\\s]+(float|double)[\\s]*\\([-]?[0-9]+(?:\\.[0-9]+)?\\)[\\s]*$", std::regex_constants::icase);
	std::smatch		m;
	Factory			f;

	if (regex_search(line, m, r1))
	{
		std::string		cmd = m[1].str();
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
		std::string		type = m[2].str();
		std::transform(type.begin(), type.end(), type.begin(), ::tolower);
		(this->*_op2[m[1]])(f.createOperand(DOUBLE, m[3].str()));
		return true;
	}
	return false;
}

bool	Parsing::checkCmd2(std::string const &line)
{
	std::regex		r1("^[\\s]*(pop|dump|add|sub|mul|div|mod|print)[\\s]*$", std::regex_constants::icase);
	std::smatch		m;

	if (regex_search(line, m, r1))
	{
		std::string		cmd = m[1].str();
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
		(this->*_op1[m[1]])();
		return true;
	}
	return false;
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
	{
		if (!checkCmd1(line) && !checkCmd2(line))
			throw std::exception();
	}
	if (line != "exit")
		throw std::exception();
	return ;
}

void	Parsing::stdoutParsing(void)
{
	std::string		line;

	initPtr();
	while (line != "exit" && !std::cin.eof())
	{
		std::getline(std::cin, line);
		if (!checkCmd1(line) && !checkCmd2(line))
			throw std::exception();
	}
	return ;
}