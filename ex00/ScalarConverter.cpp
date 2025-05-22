#include "ScalarConverter.hpp"

//~~~~~~~~~~~~~~~~~~~~~~~ Forme canonique ~~~~~~~~~~~~~~~~~~~~~~~//

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~ Methodes ~~~~~~~~~~~~~~~~~~~~~~~~~~~//

bool isInt(std::string str) {
	if (str[0] != '-' && str[0] != '+' && !isdigit(str[0]))
		return false ;
	for(unsigned long i = 1; i < str.length(); ++i) {
		if (!isdigit(str[i]))
			return false ;
	}
	return true;
}

bool isFloat(std::string str) {
	char* end; // represente pointeur vers le dernier charactere de str
	std::strtof(str.c_str(), &end); // str to float, stocke dans *end a partir du f
	if (*end == 'f' && *(end + 1) == '\0') // verifier que termine bien par f uniquement
		return true;
	return false;
}

bool isDouble(std::string str) {
	char* end;
	std::strtof(str.c_str(), &end);
	if (*end == '\0') // idem que float mais sans f final
		return true;
	return false;
}

std::string getType(std::string str) {
	if (str[0] == '\0')
		return "unknown";
	if (str.length() == 1 && !isdigit(str[0]))
		return "char";
	if (isInt(str))
		return "int";
	if (isFloat(str))
		return "float";
	if (isDouble(str))
		return "double";
	else
		return "unknown";
}

void display(int intValue, char charValue, float floatValue, double doubleValue) {
	if(std::isnan(doubleValue) || std::isinf(doubleValue))
		std::cout << "char:	impossible" << std::endl;
	else if (charValue < 32 || charValue > 126)
		std::cout << "char:	Non displayable" << std::endl;
	else
		std::cout << "char:	'" << charValue << "'" << std::endl;

	if (std::isnan(doubleValue) || std::isinf(doubleValue))
		std::cout << "int:	impossible" << std::endl;
	else
		std::cout << "int:	" << intValue << std::endl;
	
	if (floatValue == static_cast<int>(floatValue))
		std::cout << "float:	" << floatValue << ".0f" << std::endl;
	else
		std::cout << "float:	" << floatValue << "f" << std::endl;
	
	if (doubleValue == static_cast<int>(doubleValue))
		std::cout << "double:	" << doubleValue << ".0" << std::endl;
	else
		std::cout << "double:	" << doubleValue << std::endl;
	
}

void ScalarConverter::convert(std::string literal) {
	int		intValue;
	char	charValue;
	float	floatValue;
	double	doubleValue;

	std::string type = getType(literal);

	if (type == "int") {
		intValue = atoi(literal.c_str());
		charValue = static_cast<char>(intValue);
		floatValue = static_cast<float>(intValue);
		doubleValue = static_cast<double>(intValue);
		display(intValue, charValue, floatValue, doubleValue);
	} else if (type == "char") {
		charValue = literal[0];
		intValue = static_cast<int>(charValue);
		floatValue = static_cast<float>(charValue);
		doubleValue = static_cast<double>(charValue);
		display(intValue, charValue, floatValue, doubleValue);
	} else if (type == "float") {
		floatValue = strtof(literal.c_str(), NULL);
		charValue = static_cast<char>(floatValue);
		intValue = static_cast<int>(floatValue);
		doubleValue = static_cast<double>(floatValue);
		display(intValue, charValue, floatValue, doubleValue);
	} else if (type == "double") {
		doubleValue = strtod(literal.c_str(), NULL);
		charValue = static_cast<char>(doubleValue);
		intValue = static_cast<int>(doubleValue);
		floatValue = static_cast<float>(doubleValue);
		display(intValue, charValue, floatValue, doubleValue);
	} else if (type == "unknown") {
		std::cout << "Wrong string literal" << std::endl << std::endl;
	}
}










/* 

String literal: stockee en dur en memoire, en lecture seule; 
se termine tjs par \0, est ecrite entre "". Elle est constante.
Toute chaine creee ou modifiee dynamiquement n'est pas literale.
Une chaine literale est definie au moment de la compilation.
Une chaine non literale est definie au moment de l'execution.

static_cast<T>(value) : value -> T

double -> int :
static_cast<int>(double)

*/
