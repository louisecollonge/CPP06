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


void ScalarConverter::convert(std::string literal) {
	// int		intValue;
	// char	charValue;
	// float	floatValue;
	// double	doubleValue;

	// std::string type = getType(literal);
	// // std::cout << type << std::endl; //debug

	// if (type == "char") {
	// 	charDisplay(literal);
	// } else if (type == "int") {
	// 	intDisplay(literal);
	// } else if (type == "float") {
	// 	floatDisplay(literal);
	// } else if (type == "double") {
	// 	doubleDisplay(literal);
	// } else if (type == "unknown") {
	// 	std::cout << "Wrong string literal" << std::endl << std::endl;
	// }

	ScalarValue	value = convertLiteral(literal);
	displayScalarValue(value);
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
