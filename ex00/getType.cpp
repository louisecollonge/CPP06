#include "scalar.h"

bool isChar(std::string str) {
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return false;
} // un char est forcement entre single quotes pour le differencier d'un int

bool isInt(std::string str) {
	if (str[0] != '-' && str[0] != '+' && !isdigit(str[0]))
		return false ;
	for(unsigned long i = 1; i < str.length(); ++i) {
		if (!isdigit(str[i]))
			return false ;
	}
	double dbl = strtod(str.c_str(), NULL);
	if (dbl > std::numeric_limits<int>::max() || dbl < std::numeric_limits<int>::min()) // au-dela des limites du int
		return false ;
	return true;
}

bool isFloat(std::string str) {
	if (str[0] != '-' && str[0] != '+' && !isdigit(str[0]))
		return false ;
	char* end; // represente pointeur vers le dernier charactere de str
	std::strtof(str.c_str(), &end); // str to float, stocke dans *end a partir du f
	if (*end == 'f' && *(end + 1) == '\0') // verifier que termine bien par f uniquement
		return true;
	return false;
}

bool isDouble(std::string str) {
	if (str[0] != '-' && str[0] != '+' && !isdigit(str[0]))
		return false ;
	char* end;
	std::strtod(str.c_str(), &end);
	if (*end == '\0') // idem que float mais sans f final
		return true;
	return false;
}

std::string getType(std::string str) {
	if (str[0] == '\0')
		return "unknown";
	if (isChar(str))
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
