// Header for calculator tests

#include "catch.hpp"
#include "calculator.h"

TEST_CASE("Test Add function.") {

	SECTION("Test empty string.") {
		REQUIRE(Add("") == 0);
	}

    SECTION("Test single digits.") {
        REQUIRE(Add("1") == 1);
        REQUIRE(Add("2") == 2);
    }

    SECTION("Test multiple digits.") {
        REQUIRE(Add("1,2") == 3);
        REQUIRE(Add("0,2") == 2);
    }

    SECTION("Test more than 2 number") {
        REQUIRE(Add("1,2,3") == 6);
        REQUIRE(Add("1,2,3,4") == 10);
    }

    SECTION("Test strings with newlines") {
        REQUIRE(Add("1\n2") == 3);
        REQUIRE(Add("1\n2\n3") == 6);
    }

    SECTION("make sure unmatch delimiter on same line fails.") {
        REQUIRE(Add("1,\n") == -1);
    }
}
