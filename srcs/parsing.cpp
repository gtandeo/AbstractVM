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

bool	Parsing::checkCmd1(std::string const &line)
{
	std::regex		r1("^[\\s]*(push|assert)[\\s]+(int8|int16|int32)[\\s]*\\([-]?[0-9]+\\)$", std::regex_constants::icase);
	std::regex		r2("^[\\s]*(push|assert)[\\s]+(float|double)[\\s]*\\([-]?[0-9]+(?:\\.[0-9]+)?\\)[\\s]*$", std::regex_constants::icase);
	std::smatch		m;

	if (regex_search(line, m, r1))
	{
		std::string		cmd = m[1].str();
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
		std::string		type = m[2].str();
		std::transform(type.begin(), type.end(), type.begin(), ::tolower);

		return true;
	}
	return false;
}

bool	Parsing::checkCmd2(std::string const &line)
{
	std::regex		r1("^[\\s]*(pop|dump|add|sub|mul|div|mod|print)[\\s]+(int8|int16|int32)[\\s]*\\([-]?[0-9]+\\)$", std::regex_constants::icase);
	std::regex		r2("^[\\s]*(pop|dump|add|sub|mul|div|mod|print)[\\s]+(float|double)[\\s]*\\([-]?[0-9]+(?:\\.[0-9]+)?\\)[\\s]*$", std::regex_constants::icase);
	std::smatch		m;

	if (regex_search(line, m, r1))
	{
		std::string		cmd = m[1].str();
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
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
		if (!checkCmd1(line))
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
		if (!checkCmd1(line))
			throw std::exception();
	}
	return ;
}