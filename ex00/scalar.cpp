#include "ScalarValue.hpp"
#include "ScalarConverter.hpp"
#include "scalar.h"
#include <string>
#include <iostream>
#include <limits>

bool	specificCases(std::string literal) {
	if (literal == "nan" || literal == "nanf" 
		|| literal == "inf" || literal == "inff"
		|| literal == "+inf" || literal == "+inff"
		|| literal == "-inf" || literal == "-inff") {
		return true;
	}
	return false;
}

ScalarValue	convertLiteral(std::string literal)
{
	std::string type = getType(literal);
	ScalarValue	result;

	if (type == "char") 
	{
		result.validChar = true;
		result.validInt = true;
		result.validFloat = true;
		result.validDouble = true;
		
		result.c = literal[0];
		result.i = static_cast<int>(result.c);
		result.f = static_cast<float>(result.c);
		result.d = static_cast<double>(result.c);
	} 
	else if (specificCases(literal)) 
	{
		result.validChar = false;
		result.validInt = false;
		result.validFloat = true;
		result.validDouble = true;
		
		if (literal == "nan" || literal == "nanf")
			result.d = nan("");
		else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
			result.d = std::numeric_limits<double>::infinity();
		else
			result.d = -std::numeric_limits<double>::infinity();
		
		result.f = static_cast<float>(result.d);
	}
	else if (type == "unknown") 
	{
		result.validChar = false;
		result.validInt = false;
		result.validFloat = false;
		result.validDouble = false;
	}
	else {
	// double: en 1er car necessaire pour le reste
		result.validDouble = true;
		result.d = strtod(literal.c_str(), NULL);
	// float:
		result.f = static_cast<float>(result.d);
		if (result.d <= std::numeric_limits<float>::max() && result.d >= -std::numeric_limits<float>::max()) // pourquoi pas min() ?
			result.validFloat = true;
		else
			result.validFloat = false;
	// int:
		if (result.d <= std::numeric_limits<int>::max() && result.d >= std::numeric_limits<int>::min()
			&& !std::isnan(result.d) && !std::isinf(result.d)) // retourne true si c'est + l'infini ou - l'infini
		{
			result.validInt = true;
			result.i = static_cast<int>(result.d);
		} else
			result.validInt = false;
	// char:
		if (result.validInt && result.i >= 0 && result.i <= 127) {
			result.validChar = true; // verification de la printabilite dans la fonction display
			result.c = static_cast<char>(result.i);
		} else
			result.validChar = false;
	} 
	return result;
}



