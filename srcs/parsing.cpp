#include "Parsing.class.hpp"
#include <string>
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
	_container.push_front(data);
	return ;
}

/*void	Parsing::assert(IOperand const *data)
{
	;
}

void	Parsing::pop(void)
{
	;
}

void	Parsing::dump(void)
{
	;
}

void	Parsing::add(void)
{
	;
}

void	Parsing::sub(void)
{
	;
}

void	Parsing::mul(void)
{
	;
}

void	Parsing::div(void)
{
	;
}

void	Parsing::mod(void)
{
	;
}*/

void	Parsing::print(void)
{
	IOperand	const *i;
	for (std::list<IOperand const *>::iterator it = _container.begin(); it != _container.end(); it++)
	{
		i = *it;
		std::cout << i->toString() << std::endl;
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
		//execute command
		/*std::cout << "/"<< m[3] <<"/" << std::endl;
		push(f.createOperand(INT8, m[3].str()));
		push(f.createOperand(INT32, "345"));*/
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
		//execute command
		/*print();*/
		return true;
	}
	return false;
}

void	Parsing::fileParsing(const char *av)
{
	std::ifstream	file(av);
	std::string		line;

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

	while (line != "exit" && !std::cin.eof())
	{
		std::getline(std::cin, line);
		if (!checkCmd1(line) && !checkCmd2(line))
			throw std::exception();
	}
	return ;
}