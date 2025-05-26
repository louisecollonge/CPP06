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
// bool isDouble(std::string str);
// bool isFloat(std::string str);
// bool isInt(std::string str);

// // void display(int intValue, char charValue, float floatValue, double doubleValue);
// void intDisplay(std::string literal);
// void charDisplay(std::string literal);
// void floatDisplay(std::string literal);
// void doubleDisplay(std::string literal);

ScalarValue	convertLiteral(std::string literal);
void	displayScalarValue(ScalarValue value);
