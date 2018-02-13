// calculator.cpp
// Functions for calculator

#include "calculator.h"

#include <string>
using std::string;
#include <sstream>
using std::istringstream;

int Add(const string &numbers)
{
    istringstream ss(numbers);
    int num = 0;

    ss >> num;

	return num;
}
