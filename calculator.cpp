// calculator.cpp
// Functions for calculator

#include "calculator.h"

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;

static char getDelimiterFrom(const string & numbers) {
    if (numbers.size() > 3 && numbers[0] == '/' && numbers[1] == '/') {
        return numbers[2];
    }

    return ',';
}

int add(string numbers)
{
    auto delimiter = getDelimiterFrom(numbers);

    for (auto i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == delimiter) {
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
