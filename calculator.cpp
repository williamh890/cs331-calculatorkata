// calculator.cpp
// Functions for calculator

#include "calculator.h"

#include <string>
using std::string;
#include <sstream>
using std::istringstream;

int add(string numbers)
{
    for (auto i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == ',') {
            if (numbers[i + 1] > numbers.size() and numbers[i + 1] == '\n') {
                return -1;
            }

            numbers[i] = ' ';
        }
    }


    istringstream ss(numbers);

    int total = 0, num = 0;
    while(ss >> num) {
        total += num;
    }

	return total;
}
