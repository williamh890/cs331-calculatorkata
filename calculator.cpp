// calculator.cpp
// Functions for calculator

#include "calculator.h"

#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
using std::ostringstream;
#include <exception>
using std::runtime_error;

static char getDelimiterFrom(const string & numbers) {
    if (numbers.size() > 3 && numbers[0] == '/' && numbers[1] == '/') {
        return numbers[2];
    }

    return ',';
}

static string getErrorMsg(const vector<int> & negatives) {
    ostringstream os;

    os << "negatives not allowed:";
    for (auto & n : negatives) {
        os << " " << n;
    }

    return os.str();
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

    vector<int> negatives;

    int total = 0, num = 0;
    while(ss >> num) {
        if (num < 0) {
            negatives.push_back(num);
        }
        if (num >= 1000) {
            continue;
        }

        total += num;
    }

    if (negatives.size() > 0) {
        throw runtime_error(getErrorMsg(negatives));
    }

	return total;
}
