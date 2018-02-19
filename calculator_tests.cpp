// Header for calculator tests

#include "catch.hpp"
#include "calculator.h"

#include <string>
using std::string;
#include <exception>
using std::runtime_error;

TEST_CASE("Test add function.") {

	SECTION("Test empty string.") {
		REQUIRE(add("") == 0);
	}

    SECTION("Test single digits.") {
        REQUIRE(add("1") == 1);
        REQUIRE(add("2") == 2);
    }

    SECTION("Test multiple digits.") {
        REQUIRE(add("1,2") == 3);
        REQUIRE(add("0,2") == 2);
    }

    SECTION("Test more than 2 number") {
        REQUIRE(add("1,2,3") == 6);
        REQUIRE(add("1,2,3,4") == 10);
    }

    SECTION("Test strings with newlines") {
        REQUIRE(add("1\n2") == 3);
        REQUIRE(add("1\n2\n3") == 6);
    }

    SECTION("make sure unmatch delimiter on same line fails.") {
        REQUIRE(add("1,\n") == -1);
    }

    SECTION("allow custom delimiters") {
        REQUIRE(add("//;\n1;2"));
    }

    SECTION("negative numbers throw error msg") {
        bool didThrow = false;
        string msg = "";

        try {
            add("-1,-2");
        } catch(runtime_error & e) {
            didThrow = true;
            msg = e.what();
        }

        REQUIRE(didThrow);
        REQUIRE(msg == "negatives not allowed: -1 -2");
    }

    SECTION("numbers larger than 1000 are ignored") {
        REQUIRE(add("1001, 2") == 2);
    }

    SECTION("delimiters of more than one character work") {
        REQUIRE(add("//[***]\n1***2***3") == 6);
    }

    SECTION("multiple one char delimiters") {
        REQUIRE(add("//[*][%]\n1*2%3") == 6);
    }

    SECTION("multiple multi char delimiters") {
        REQUIRE(add("//[***][^%]\n1***2^%3") == 6);
    }

}
