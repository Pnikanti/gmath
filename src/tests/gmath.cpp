#define CATCH_CONFIG_MAIN 

#include <catch2.h>
#include "gmath.h"

TEST_CASE("2x2 matrix calculations")
{
	
	SECTION("Sum of two matrices should provide correct output")
	{
		mat2f a = mat2f(0.5f, 0.1f, 0.2f, 0.3f) + 
				  mat2f(0.5f, 0.9f, 0.8f, 0.7f);

		REQUIRE(a == mat2f(1.0f));
	}

	SECTION("Difference of two matrices should provide correct output")
	{
		mat2f a = mat2f(1.5f, 2.2f, 10.2f, 5.3f) -
				  mat2f(0.5f, 1.2f, 9.2f, 4.3f);

		REQUIRE(a == mat2f(1.0f));
	}

	SECTION("Product of two matrices should provide correct output")
	{
		mat2f a = mat2f(1.5f, 2.2f, 10.2f, 5.3f) *
				  mat2f(0.5f, 1.2f, 9.2f, 4.3f);

		REQUIRE(a == mat2f(12.99f, 7.46f, 57.66f, 43.03f));
	}

	SECTION("Sum of matrix and scalar should provide correct output")
	{
		mat2f a = mat2f(1.5f, 2.2f, 10.2f, 5.3f) + 1.0f;

		REQUIRE(a == mat2f(2.5f, 3.2f, 11.2f, 6.3f));
	}

	SECTION("Difference of matrix and scalar should provide correct output")
	{
		mat2f a = mat2f(1.5f, 2.2f, 10.2f, 5.3f) - 1.0f;

		REQUIRE(a == mat2f(0.5f, 1.2f, 9.2f, 4.3f));
	}

	SECTION("Quotient of matrix and scalar should provide correct output")
	{
		mat2f a = mat2f(1.5f, 2.2f, 10.2f, 5.3f) / 2.0f;

		REQUIRE(a == mat2f(0.75f, 1.1f, 5.1f, 2.65f));
	}

	SECTION("Product of matrix and scalar should provide correct output")
	{
		mat2f a = mat2f(1.5f, 2.2f, 10.2f, 5.3f) * 2.0f;

		REQUIRE(a == mat2f(3.0f, 4.4f, 20.4f, 10.6f));
	}


}

