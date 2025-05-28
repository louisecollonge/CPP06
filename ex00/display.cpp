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
		
		if (value.validFloat) 
		{
			if (std::isnan(value.f))
				std::cout << "float:\tnanf" << std::endl;
			else if (std::isinf(value.f)) {
				if (value.f > 0)
					std::cout << "float:\t+inff" << std::endl;
				else
					std::cout << "float:\t-inff" << std::endl;
			} else {
				float intpart;
				if (value.f == 0.0f || value.f == -0.0f) // cas particulier de +-0.0f
					std::cout << "float:\t0.0f" << std::endl;
				else if (::modff(value.f, &intpart) == 0.0f){ // teste si partie fractionnaire est nulle
					if (fabsf(value.f) >= 1e4f || fabsf(value.f) < 1e-4f) // teste valeur absolue: si nb trop long, on affichera en 10^x
						std::cout << "float:\t" << std::scientific << std::setprecision(1) << value.f << "f" << std::endl; // setprecision force l'affichage de 1 chiffre apres la virgule
					else
						std::cout << "float:\t" << std::fixed << std::setprecision(1) << value.f << "f" << std::endl; // fixed force affichage partie entiere sans virgule dedans cad pas de 10^x: 42.0f et pas 4.2e1f
				} else
					std::cout << "float:\t" << std::fixed << std::setprecision(1) << value.f << "f" << std::endl;
			}
		}
		else
			std::cout << "float:\timpossible" << std::endl;
	}
	{ // double:
		if (value.validDouble) {
			if (std::isnan(value.d))
				std::cout << "double:\tnan" << std::endl;
			else if (std::isinf(value.d)) {
				if (value.d > 0)
					std::cout << "double:\t+inf" << std::endl;
				else
					std::cout << "double:\t-inf" << std::endl;
			} else {
				double intpart;
				if (value.d == 0.0 || value.d == -0.0) // cas particulier de +-0.0
					std::cout << "double:\t0.0" << std::endl;
				else if (::modf(value.d, &intpart) == 0.0) { // teste si partie fractionnaire est nulle
					if (fabs(value.d) >= 1e4 || fabs(value.d) < 1e-4) // devient trop long, on affichera exponentielle de 10 avec std::scientific. 0 et un cas particulier a ajouter.
						std::cout << "double:\t" << std::scientific << std::setprecision(1) << value.d << std::endl; // setprecision force l'affichage d'un chiffre apres la virgule
					else
						std::cout << "double:\t" << std::fixed << std::setprecision(1) << value.d << std::endl;
				} else
					std::cout << "double:\t" << std::fixed << std::setprecision(1) << value.d << std::endl;
			}
		} 
		else
			std::cout << "double:\timpossible" << std::endl;
	}
}


