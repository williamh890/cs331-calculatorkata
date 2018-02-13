// Header for calculator tests

#include "catch.hpp"
#include "calculator.h"

TEST_CASE("Test Add function.") {

	SECTION("Test empty string.") {
		REQUIRE(Add("") == 0);
	}
}
