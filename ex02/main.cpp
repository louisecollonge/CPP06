#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Wrong.hpp"
#include <ctime> // pour time
#include <cstdlib> // pour srand

#define PINK	 	"\033[0;35m"
#define ORANGE		"\033[38;5;214m"
#define RESET		"\033[0m"


Base *generate(void) 
{
	std::srand(std::time(NULL));
	int third = std::rand() % 3;

	switch (third) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return new A();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << ORANGE << "Type A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << ORANGE << "Type B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << ORANGE << "Type C" << RESET << std::endl;
	else
		std::cout << ORANGE << "Unknown type" << RESET << std::endl;
}

void identify(Base &p)
{
	bool found = false;
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << PINK << "Type A" << RESET << std::endl;
		found = true;
	} catch (std::exception &e) {
		;
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << PINK << "Type B" << RESET << std::endl;
		found = true;
	} catch (std::exception &e) {
		;
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << PINK << "Type C" << RESET << std::endl;
		found = true;
	} catch (std::exception &e) {
		;
	}
	if (found == false)
		std::cout << PINK << "Unknown type" << RESET << std::endl;
}

int main(void) {
	std::cout << "~ Test with correct object: ~" << std::endl;
	Base *test = generate();
	identify(test);
	identify(*test);
	delete test;

	std::cout << "\n~ Test with wrong object: ~" << std::endl;
	Base *wrong = new Wrong();
	identify(wrong);
	identify(*wrong);
	delete wrong;
	return 0 ;
}
