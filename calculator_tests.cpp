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

    }
}
