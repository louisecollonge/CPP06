#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cerrno>
#include "ScalarValue.hpp"

std::string getType(std::string str);
ScalarValue	convertLiteral(std::string literal);
void		displayScalarValue(ScalarValue value);
