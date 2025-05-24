#include "ScalarConverter.hpp"

#define PINK	 	"\033[0;35m"
#define RESET		"\033[0m"


int main(int ac, char** av) {
//* Program's arguments:

	for (int i = 1; i < ac; ++i) {
		std::cout << PINK << av[i] << ": " << RESET << std::endl;
		ScalarConverter::convert(av[i]);
		std::cout << std::endl;
	}

//* My tests:
	std::string ex0 = "0";
	std::cout << PINK << std::endl << ex0 << ":	" << getType(ex0) << RESET << std::endl;
	ScalarConverter::convert(ex0);

	std::string ex1 = "nan";
	std::cout << PINK << std::endl << ex1 << ":	" << getType(ex1) << RESET << std::endl;
	ScalarConverter::convert(ex1);

	std::string ex2 = "42.0f";
	std::cout << PINK << std::endl << ex2 << ":	" << getType(ex2) << RESET << std::endl;
	ScalarConverter::convert(ex2);

	std::string ex3 = "2147483648";
	std::cout << PINK << std::endl << ex3 << ":	" << getType(ex3) << RESET << std::endl;
	ScalarConverter::convert(ex3);

	std::string ex4 = "e";
	std::cout << PINK << std::endl << ex4 << ":	" << getType(ex4) << RESET << std::endl;
	ScalarConverter::convert(ex4);

	std::string ex5 = "-2147483648";
	std::cout << PINK << std::endl << ex5 << ":	" << getType(ex5) << RESET << std::endl;
	ScalarConverter::convert(ex5);	

	std::string ex6 = "+inff";
	std::cout << PINK << std::endl << ex6 << ":	" << getType(ex6) << RESET << std::endl;
	ScalarConverter::convert(ex6);

	std::string ex7 = "3.14567891223445465657";
	std::cout << PINK << std::endl << ex7 << ":	" << getType(ex7) << RESET << std::endl;
	ScalarConverter::convert(ex7);

	std::string ex8 = "nanf";
	std::cout << PINK << std::endl << ex8 << ":	" << getType(ex8) << RESET << std::endl;
	ScalarConverter::convert(ex8);

	std::string ex9 = "-inf";
	std::cout << PINK << std::endl << ex9 << ":	" << getType(ex9) << RESET << std::endl;
	ScalarConverter::convert(ex9);

	std::string ex10 = "-infff";
	std::cout << PINK << std::endl << ex10 << ":	" << getType(ex10) << RESET << std::endl;
	ScalarConverter::convert(ex10);

	std::string ex11 = "44truc faux44";
	std::cout << PINK << std::endl << ex11 << ":	" << getType(ex11) << RESET << std::endl;
	ScalarConverter::convert(ex11);
}
