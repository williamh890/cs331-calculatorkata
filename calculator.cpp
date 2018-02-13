// calculator.cpp
// Functions for calculator

#include "calculator.h"

#include <string>
using std::string;
#include <sstream>
using std::istringstream;

int Add(string numbers)
{
    for (auto c = 0; (unsigned int)c < numbers.size(); ++c) {
        if (numbers[c] == ',') {
            numbers[c] = ' ';
        }
    }


    istringstream ss(numbers);

    int total = 0, num = 0;
    while(ss >> num) {
        total += num;
    }

	return total;
}
