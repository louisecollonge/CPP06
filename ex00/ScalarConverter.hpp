#pragma once

#include <iostream>
#include <string>
#include <cstdlib> // pour strtof
#include <cctype> // pour isdigit
#include <cmath> // poour isnan et isinf
#include "scalar.h"
#include "ScalarValue.hpp"

class	ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
	
	public:
		~ScalarConverter();
		static void convert(std::string literal); // static permet d'utiliser cette methode sans instancier la classe
};
