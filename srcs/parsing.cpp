#include <fstream>
#include <iostream>

void	fileParsing(const char *av)
{
	std::ifstream	file(av);
	std::string		line;

	while (std::getline(file, line) && line != "exit")
	{
		//execCmd();
	}
	return ;
}

void	stdoutParsing(void)
{
	std::string		line;

	while (line != "exit" && !std::cin.eof())
	{
		std::getline(std::cin, line);
		//execCmd();
	}
	return ;
}