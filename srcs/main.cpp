#include "Parsing.h"
#include "Operand.class.hpp"
#include "Factory.class.hpp"

int		main(int ac, char **av)
{
	if (ac == 1)
		stdoutParsing();
	else if (ac == 2)
		fileParsing(av[1]);
	else
		std::cout << "usage: ./avm [file ...]" << std::endl;
	/*Factory	f;
	const IOperand	*i = f.createOperand(INT8, "32");
	
	std::cout << i->getType() << std::endl;
	std::cout << i->toString() << std::endl;*/
	return 0;
}
