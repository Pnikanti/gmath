#define CATCH_CONFIG_MAIN 

#include <catch2.h>
#include "gmath.h"

TEST_CASE("vector2 calculations", "[!mayfail]")
{
	SECTION("Sum of two vectors should provide correct output")
	{
		vec2f a = vec2f(2.0f, 1.0f) + vec2f(3.0f, 4.2f);
		REQUIRE(a == vec2f(5.0f, 5.2f));
	}

	SECTION("Difference of two vectors should provide correct output")
	{
		vec2f a = vec2f(10.2f, 763.0f) - vec2f(5.2f, 760.0f);
		REQUIRE(a == vec2f(5.0f, 3.0f));
	}

	SECTION("Product of two vectors should provide correct output")
	{
		vec2f a = vec2f(5.0f) * vec2f(1.0f, 5.0f);
		REQUIRE(a == vec2f(5.0f, 25.0f));
	}

	SECTION("Sum of vector and scalar should provide correct output")
	{
		vec2f a = vec2f(5.0f, 2.5f) + 1.0f;
		REQUIRE(a == vec2f(6.0f, 3.5f));
	}

	SECTION("Difference of vector and scalar should provide correct output")
	{
		vec2f a = vec2f(5.0f, 1.4f) - 0.3f;
		REQUIRE(a == vec2f(4.7f, 1.1f));
	}

	SECTION("Quotient of vector and scalar should provide correct output")
	{
		vec2f a = vec2f(2.5f, 5.0f) / 2.0f;
		REQUIRE(a == vec2f(1.25f, 2.5f));
	}

	SECTION("Product of vector and scalar should provide correct output")
	{
		vec2f a = vec2f(2.5f, 5.0f) * 2.0f;
		REQUIRE(a == vec2f(5.0f, 10.0f));
	}
}


TEST_CASE("vector3 calculations", "[!mayfail]")
{
	SECTION("Sum of two vectors should provide correct output")
	{
		vec3f a = vec3f(2.0f, 1.0f, 2.0f) + vec3f(3.0f, 4.2f, 3.0f);
		REQUIRE(a == vec3f(5.0f, 5.2f, 5.0f));
	}

	SECTION("Difference of two vectors should provide correct output")
	{
		vec3f a = vec3f(10.2f, 763.0f, 0.5f) - vec3f(5.2f, 760.0f, 0.2f);
		REQUIRE(a == vec3f(5.0f, 3.0f, 0.3f));
	}

	SECTION("Product of two vectors should provide correct output")
	{
		vec3f a = vec3f(5.0f) * vec3f(1.0f, 5.0f, 0.0f);
		REQUIRE(a == vec3f(5.0f, 25.0f, 0.0f));
	}

	SECTION("Sum of vector and scalar should provide correct output")
	{
		vec3f a = vec3f(5.0f, 2.5f, 7.0f) + 1.0f;
		REQUIRE(a == vec3f(6.0f, 3.5f, 8.0f));
	}

	SECTION("Difference of vector and scalar should provide correct output")
	{
		vec3f a = vec3f(5.0f, 1.4f, 0.3f) - 0.3f;
		REQUIRE(a == vec3f(4.7f, 1.1f, 0.0f));
	}

	SECTION("Quotient of vector and scalar should provide correct output")
	{
		vec3f a = vec3f(2.5f, 5.0f, 10.0f) / 2.0f;
		REQUIRE(a == vec3f(1.25f, 2.5f, 5.0f));
	}

	SECTION("Product of vector and scalar should provide correct output")
	{
		vec3f a = vec3f(2.5f, 5.0f, 10.0f) * 2.0f;
		REQUIRE(a == vec3f(5.0f, 10.0f, 20.0f));
	}
}

TEST_CASE("vector4 calculations", "[!mayfail]")
{
	SECTION("Sum of two vectors should provide correct output")
	{
		vec4f a = vec4f(2.0f, 1.0f, 2.0f, 0.2f) + vec4f(3.0f, 4.2f, 3.0f, 0.5f);
		REQUIRE(a == vec4f(5.0f, 5.2f, 5.0f, 0.7f));
	}

	SECTION("Difference of two vectors should provide correct output")
	{
		vec4f a = vec4f(10.2f, 763.0f, 0.5f, 0.2f) - vec4f(5.2f, 760.0f, 0.2f, 0.1f);
		REQUIRE(a == vec4f(5.0f, 3.0f, 0.3f, 0.1f));
	}

	SECTION("Product of two vectors should provide correct output")
	{
		vec4f a = vec4f(5.0f) * vec4f(1.0f, 5.0f, 0.0f, 25.0f);
		REQUIRE(a == vec4f(5.0f, 25.0f, 0.0f, 125.0f));
	}

	SECTION("Sum of vector and scalar should provide correct output")
	{
		vec4f a = vec4f(5.0f, 2.5f, 7.0f, 0.0f) + 1.0f;
		REQUIRE(a == vec4f(6.0f, 3.5f, 8.0f, 1.0f));
	}

	SECTION("Difference of vector and scalar should provide correct output")
	{
		vec4f a = vec4f(5.0f, 1.4f, 0.3f, 0.0f) - 0.3f;
		REQUIRE(a == vec4f(4.7f, 1.1f, 0.0f, -0.3f));
	}

	SECTION("Quotient of vector and scalar should provide correct output")
	{
		vec4f a = vec4f(2.5f, 5.0f, 10.0f, -5.0f) / 2.0f;
		REQUIRE(a == vec4f(1.25f, 2.5f, 5.0f, -2.5f));
	}

	SECTION("Product of vector and scalar should provide correct output")
	{
		vec4f a = vec4f(2.5f, 5.0f, 10.0f, -10.0f) * 2.0f;
		REQUIRE(a == vec4f(5.0f, 10.0f, 20.0f, -20.0f));
	}
}

TEST_CASE("2x2 matrix calculations", "[!mayfail]")
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

// WORK IN PROGRESS
//TEST_CASE("3x3 matrix calculations", "[!mayfail]")
//{
//
//	SECTION("Sum of two matrices should provide correct output")
//	{
//		mat3f a = mat3f(0.5f, 0.1f, 0.2f,
//						0.3f, 0.2f, 0.5f,
//						0.2f, 0.5f, 0.1f) +
//				  mat3f(0.5f, 0.9f, 0.8f,
//						0.2f, 0.3f, 0.7f,
//						0.7f, 0.4f, 0.8f);
//
//		REQUIRE(a == mat3f(1.0f));
//	}
//
//	SECTION("Difference of two matrices should provide correct output")
//	{
//		mat3f a = mat3f(1.5f, 2.2f, 10.2f, 5.3f) -
//			mat3f(0.5f, 1.2f, 9.2f, 4.3f);
//
//		REQUIRE(a == mat3f(1.0f));
//	}
//
//	SECTION("Product of two matrices should provide correct output")
//	{
//		mat3f a = mat3f(1.5f, 2.2f, 10.2f, 5.3f) *
//			mat3f(0.5f, 1.2f, 9.2f, 4.3f);
//
//		REQUIRE(a == mat3f(12.99f, 7.46f, 57.66f, 43.03f));
//	}
//
//	SECTION("Sum of matrix and scalar should provide correct output")
//	{
//		mat3f a = mat3f(1.5f, 2.2f, 10.2f, 5.3f) + 1.0f;
//
//		REQUIRE(a == mat3f(2.5f, 3.2f, 11.2f, 6.3f));
//	}
//
//	SECTION("Difference of matrix and scalar should provide correct output")
//	{
//		mat3f a = mat3f(1.5f, 2.2f, 10.2f, 5.3f) - 1.0f;
//
//		REQUIRE(a == mat3f(0.5f, 1.2f, 9.2f, 4.3f));
//	}
//
//	SECTION("Quotient of matrix and scalar should provide correct output")
//	{
//		mat3f a = mat3f(1.5f, 2.2f, 10.2f, 5.3f) / 2.0f;
//
//		REQUIRE(a == mat3f(0.75f, 1.1f, 5.1f, 2.65f));
//	}
//
//	SECTION("Product of matrix and scalar should provide correct output")
//	{
//		mat3f a = mat3f(1.5f, 2.2f, 10.2f, 5.3f) * 2.0f;
//
//		REQUIRE(a == mat3f(3.0f, 4.4f, 20.4f, 10.6f));
//	}
//}