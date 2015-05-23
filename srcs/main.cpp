#include "Operand.class.hpp"
#include "Factory.class.hpp"

int		main(void)
{
	Factory	f;
	const IOperand	*i = f.createOperand(INT8, "32");
	
	std::cout << i->getType() << std::endl;
	std::cout << i->toString() << std::endl;
	return 0;
}
