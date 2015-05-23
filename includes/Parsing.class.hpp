#ifndef PARSING_HPP
# define PARSING_HPP

# include <fstream>
# include <iostream>
# include <vector>

class	Parsing {
public:
	Parsing(void);
	Parsing(Parsing const &src) {*this = src;}
	~Parsing(void) {}

	bool	checkCmd(std::string const &line);
	void	fileParsing(const char *av);
	void	stdoutParsing(void);

private:
	std::vector<std::string>	_cmds;

};

#endif