#include "scalar.h"

void	displayScalarValue(ScalarValue value)
{
	{ // char:
		if (value.validChar) {
			if (!std::isprint(value.i))
				std::cout << "char:	Non displayable" << std::endl;
			else
				std::cout << "char:	'" << value.c << "'" << std::endl;
		} else
			std::cout << "char:	impossible" << std::endl;
	}
	{ // int:
		if (value.validInt)
			std::cout << "int:	" << value.i << std::endl;
		else
			std::cout << "int:	impossible" << std::endl;
	}
	{ // float:
		if (value.validFloat) {
			std::cout << "float:	";
			if (std::isinf(value.f) && value.f > 0) // forcer l'afficher du + pour inff
				std::cout << "+";
			if (value.f == static_cast<int>(value.f) // si cast en int == float, alors rien apres la virgule: forcer affichage .0f
				&& (value.f < 1e+6 && value.f >= 1e+4)) // l'affichage est en format exponentiel en dehors de ces limites, auquel cas pas besoin de .0
				std::cout << value.f << ".0f" << std::endl;
			else
				std::cout << value.f << "f" << std::endl;
		} else
			std::cout << "float:	impossible" << std::endl;
	}
	{ // double:
		if (value.validDouble) {
			std::cout << "double:	";
			if (std::isinf(value.d) && value.d > 0) // forcer l'afficher du + pour inf
				std::cout << "+";
			if (value.d == static_cast<int>(value.d) // si cast en int == double, alors rien apres la virgule: forcer affichage .0
				&& (value.d < 1e+6 && value.d >= 1e+4)) // l'affichage est en format exponentiel en dehors de ces limites, auquel cas pas besoin de .0
				std::cout << value.d << ".0" << std::endl;
			else
				std::cout << value.d << std::endl;
		} else
			std::cout << "double:	impossible" << std::endl;
	}
}


