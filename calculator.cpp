// calculator.cpp
// Functions for calculator

#include "calculator.h"

#include <string>
using std::string;
#include <sstream>
using std::istringstream;

int Add(string numbers)
{
    for (auto & c : numbers) {
        if (c == ',') {
            c = ' ';
        }
    }


    istringstream ss(numbers);

    int total = 0, num = 0;
    while(ss >> num) {
        total += num;
    }

	return total;
}
