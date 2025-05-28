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
	ScalarValue	value = convertLiteral(literal);
	displayScalarValue(value);
}

/* 
String literal: stockee en dur en memoire, en lecture seule; 
se termine tjs par \0, est ecrite entre "". Elle est constante.
Toute chaine creee ou modifiee dynamiquement n'est pas literale.

Une chaine literale est definie au moment de la compilation.
Une chaine non literale est definie au moment de l'execution.

Static_cast :
Permet de convertir des types connus, sans verification a l'execution

static_cast<newType>(oldType value) :		oldType value -> newType value
double -> int :								static_cast<int>(double)
*/
