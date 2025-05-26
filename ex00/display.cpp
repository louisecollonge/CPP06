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
			double intpart;
			if (value.f == 0.0 || value.f == -0.0) // afficher 0.0f si on a 0 ou -0
				std::cout << "0.0f" << std::endl;
			else if (std::modf(value.d, &intpart) == 0.0){ // teste si partie fractionnaire est nulle
				if ((value.f != 0.0f) && (value.f >= 1e4 || value.f < 1e-4) && (value.f >= -1e-4 || value.f <= -1e4)) // devient trop long, on affichera exponentielle de 10 avec std::scientific. 0 et un cas particulier a ajouter.
					std::cout << std::scientific << std::setprecision(7) << value.f << "f" << std::endl; // setprecision force l'affichage d'un chiffre apres la virgule
				else
					std::cout << std::fixed << std::setprecision(1) << value.f << "f" << std::endl;
			} else
				std::cout << std::fixed << std::setprecision(7) << value.f << "f" << std::endl;
		} else if (std::isinf(value.f)) {
			if (value.f > 0)
				std::cout << "float:	+inff" << std::endl;
			else
				std::cout << "float:	-inff" << std::endl;
		} else
			std::cout << "float:	impossible" << std::endl;
	}
	{ // double:
		if (std::isnan(value.d))
			std::cout << "double:	nan" << std::endl;
		else if (std::isinf(value.d)) {
			if (value.d > 0)
				std::cout << "double:	+inf" << std::endl;
			else
				std::cout << "double:	-inf" << std::endl;
		} else if (value.validDouble) {
			double intpart;
			if (value.d == 0.0 || value.d == -0.0) // afficher 0.0 si on a 0 ou -0
				std::cout << "double:	" << "0.0" << std::endl;
			else if (std::modf(value.d, &intpart) == 0.0) { // teste si partie fractionnaire est nulle
				if ((value.d != 0.0) && (value.d >= 1e4 || value.d < 1e-4) && (value.d >= -1e-4 || value.d <= -1e4)) // devient trop long, on affichera exponentielle de 10 avec std::scientific. 0 et un cas particulier a ajouter.
					std::cout << "double:	" << std::scientific << std::setprecision(16) << value.d << std::endl; // setprecision force l'affichage d'un chiffre apres la virgule
				else
					std::cout << "double:	" << std::fixed << std::setprecision(1) << value.d << std::endl;
			} else
				std::cout << "double:	" << std::fixed << std::setprecision(16) << value.d << std::endl;
		} else
			std::cout << "double:	impossible" << std::endl;
	}
}


