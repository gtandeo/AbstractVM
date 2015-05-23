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

bool	Parsing::checkCmd(std::string const &line)
{
	if (std::find(_cmds.begin(), _cmds.end(), line) != _cmds.end())
		return true;
	return false;
}

void	Parsing::fileParsing(const char *av)
{
	std::ifstream	file(av);
	std::string		line;

	while (std::getline(file, line) && line != "exit")
	{
		if (!checkCmd(line))
			throw std::exception();
		//execCmd(line);
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
		if (!checkCmd(line))
			throw std::exception();
		//execCmd(line);
	}
	return ;
}