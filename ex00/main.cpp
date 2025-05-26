#include "ScalarConverter.hpp"

#define PINK	 	"\033[0;35m"
#define ORANGE		"\033[38;5;214m"
#define RESET		"\033[0m"

void myTests() {
	std::cout << ORANGE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
	std::cout << ORANGE << "            MY TESTS            " << RESET << std::endl;
	std::cout << ORANGE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
	std::string tests[] = {
		"0", "42", "-42", 
		"4.2", "-4.2", "4.2f", "-4.2f", "42.0f", "42.0",
		"'a'", "z", "A", "'Z'",
		"\n", "\t", "\b", "\x01",
		"2147483648", "-2147483649", // INT_MAX + 1 et INT_MIN - 1
		"340282346638528859811704183484516925440.0f", // Float max
		"1e39f",                                      // Float overflow
		"1e309",                                      // Double overflow
		"-1e309",
		"nan", "+inf", "-inf", "nanf", "+inff", "-inff",
		"-128", "-129",
		"9223372036854775807", // Long long max
		"-9223372036854775808", // Long long min
		"  42", "42  ", " 42.0f ",
		"0.0", "0.0f", "-0.0", "-0.0f",
		"42f42", "4.2.3", "--4.2f", "4..2", "4f.2", "+-42" "42ff", "42.0ff", "hello", "42hello",
	};
	for (size_t i = 0; i < sizeof(tests) / sizeof(std::string); ++i) {
		std::cout << ORANGE << "Test #" << i + 1 << ": \"" << tests[i] << "\"" << " (" << getType(tests[i]) << ")" << RESET << std::endl;
		ScalarConverter::convert(tests[i]);
		std::cout << ORANGE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
	}
}


int main(int ac, char** av) {
	if (ac > 1) {
		std::cout << PINK << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
		std::cout << PINK << "           YOUR TESTS           " << RESET << std::endl;
		std::cout << PINK << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
	}
	for (int i = 1; i < ac; ++i) {
		std::cout << PINK << av[i] << ": " << RESET << std::endl;
		ScalarConverter::convert(av[i]);
		std::cout << PINK << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
	}
	// myTests();
}

