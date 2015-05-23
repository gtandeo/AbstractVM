#include "Parsing.class.hpp"
#include "Operand.class.hpp"
#include "Factory.class.hpp"

int		main(int ac, char **av)
{
	Parsing	p;
	if (ac == 1)
		try {
			p.stdoutParsing();
		}
		catch (std::exception &e) {
			e.what();
		}
	else if (ac == 2)
	{
		try {
			p.fileParsing(av[1]);
		}
		catch (std::exception &e) {
			e.what();
		}
	}
	else
		std::cout << "usage: ./avm [file ...]" << std::endl;
	return 0;
}
