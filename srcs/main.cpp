#include "Parsing.class.hpp"
#include "Operand.class.hpp"
#include "Factory.class.hpp"

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	IOperand	const *i = new Operand("34", INT8);
	IOperand	const *j = new Operand("345.4", DOUBLE);

	std::cout << i->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->toString() << std::endl;
	std::cout << j->toString() << std::endl;

	IOperand	const *k = *i + *j;
	std::cout << k->getType() << std::endl;
	std::cout << k->toString() << std::endl;
	/*Parsing	p;
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
	*/return 0;
}
