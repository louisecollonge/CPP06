#pragma once

// #include <iostream>
// #include <string>
// #include <cstdlib> // pour strtof
// #include <cctype> // pour isdigit
// #include <cmath> // poour isnan et isinf
// #include "scalar.h"

struct	ScalarValue {
	bool	validChar;
	char	c;

	bool	validInt;
	int		i;

	bool	validFloat;
	float	f;

	bool	validDouble;
	double	d;
};
