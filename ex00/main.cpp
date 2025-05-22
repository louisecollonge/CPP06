#include "ScalarConverter.hpp"

#define PINK	 	"\033[0;35m"
#define RESET		"\033[0m"

//todo au dela de int min et max
//todo f mal place dans ...e+...f

int main(int ac, char** av) {
//* Program's arguments:

	for (int i = 1; i < ac; ++i) {
		std::cout << PINK << av[i] << ": " << RESET << std::endl;
		ScalarConverter::convert(av[i]);
		std::cout << std::endl;
	}

//* My tests:

	// std::string integer = "2147483647";
	// std::cout << PINK << std::endl << integer << ":	" << RESET << std::endl;
	// ScalarConverter::convert(integer);

	// std::string charactere = "e";
	// std::cout << PINK << std::endl << charactere << ":	" << RESET << std::endl;
	// ScalarConverter::convert(charactere);

	// std::string virguleFlottante = "42.0f";
	// std::cout << PINK << std::endl << virguleFlottante << ":	" << RESET << std::endl;
	// ScalarConverter::convert(virguleFlottante);	

	// std::string aussiFloat = "+inff";
	// std::cout << PINK << std::endl << aussiFloat << ":	" << RESET << std::endl;
	// ScalarConverter::convert(aussiFloat);

	// std::string virguleDouble = "3.145";
	// std::cout << PINK << std::endl << virguleDouble << ":	" << RESET << std::endl;
	// ScalarConverter::convert(virguleDouble);

	// std::string aussiDouble = "nan";
	// std::cout << PINK << std::endl << aussiDouble << ":	" << RESET << std::endl;
	// ScalarConverter::convert(aussiDouble);
}
