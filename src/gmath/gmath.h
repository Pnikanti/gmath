#pragma once

#include <cmath>
#include <iostream>

/*
	Stupidly simple maths library.
*/


// Macros

#ifdef DEBUG
void OUTOFBOUNDSCHECK(int index, int bounds)
{
	if (index >= bounds)
		throw std::out_of_range("Index out of range!");
}
#else
void OUTOFBOUNDSCHECK(int index, int bounds) {}
#endif

template<typename T>
struct vec2
{

	// Constructors

	vec2(T _x, T _y) : x(_x), y(_y) {}

	vec2(const vec2<T>& a) : x(a.x), y(a.y) {}

	// Scalar operation
	vec2(const T& a) : x(a), y(a) {}

	// Methods

	T length()
	{
		return sqrt(
			x * x +
			y * y
		);
	}

	vec2<T> normalized()
	{
		return vec2<T>(*this / length());
	}

	// Static methods

	static T dot(const vec2<T>& a, const vec2<T>& b)
	{
		return a.x * b.x + a.y * b.y;
	}

	// Operator overloads

	T operator[](int index)
	{
		OUTOFBOUNDSCHECK(sizeof(T) * index, bounds);
		return _a[index];
	}


	bool operator== (const vec2<T>& a) const
	{
		return (x == a.x) && (y == a.y);
	}

	vec2<T> operator+ (const vec2<T>& a)
	{
		return vec2<T>(
			x + a.x,
			y + a.y
		);
	}

	// Scalar operation
	vec2<T> operator+ (const T& a)
	{
		return vec2<T>(
			x + a,
			y + a
		);
	}

	vec2<T> operator- (const vec2<T>& a)
	{
		return vec2<T>(
			x - a.x,
			y - a.y
		);
	}

	// Scalar operation
	vec2<T> operator- (const T& a)
	{
		return vec2<T>(
			x - a,
			y - a
		);
	}

	vec2<T> operator/ (const vec2<T>& a)
	{
		return vec2<T>(
			x / a.x, 
			y / a.y
		);
	}

	// Scalar operation
	vec2<T> operator/ (const T& a)
	{
		return vec2<T>(
			x / a,
			y / a
		);
	}

	vec2<T> operator* (const vec2<T>& a)
	{
		return vec2<T>(
			x * a.x,
			y * a.y
		);
	}

	// Scalar operation
	vec2<T> operator* (const T& a)
	{
		return vec2<T>(
			x * a,
			y * a
		);
	}

	friend std::ostream& operator<< (std::ostream& stream, const vec2<T>& a)
	{
		return stream << "(" << a.x << ", " << a.y << ")";
	}

	// Attributes

	union {
		struct { T x, y; };
		T _a[2];
	};

	int bounds = sizeof(T) * 2;
};

template<typename T>
struct vec3
{

	// Constructors 

	vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

	vec3(const vec3<T>& a) : x(a.x), y(a.y), z(a.z) {}

	// Scalar operation
	vec3(const T& a) : x(a), y(a), z(a) {}

	// Methods

	T length()
	{
		return sqrt(
			x * x +
			y * y +
			z * z
		);
	}

	vec3<T> normalized()
	{
		return vec3<T>(*this / length());
	}

	// Static methods

	static T dot(const vec3<T>& a, const vec3<T>& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	// Operator overloads

	T operator[](int index)
	{
		OUTOFBOUNDSCHECK(sizeof(T) * index, bounds);
		return _a[index];
	}

	vec3<T> operator+ (const vec3<T>& a)
	{
		return vec3<T>(
			x + a.x,
			y + a.y,
			z + a.z
		);
	}

	// Scalar operation
	vec3<T> operator+ (const T& a)
	{
		return vec3<T>(
			x + a,
			y + a,
			z + a
		);
	}

	vec3<T> operator- (const vec3<T>& a)
	{
		return vec3<T>(
			x - a.x,
			y - a.y,
			z - a.z
		);
	}

	// Scalar operation
	vec3<T> operator- (const T& a)
	{
		return vec3<T>(
			x - a, 
			y - a,
			z - a
		);
	}

	vec3<T> operator/ (const vec3<T>& a)
	{
		return vec3<T>(
			x / a.x,
			y / a.y, 
			z / a.z
		);
	}

	// Scalar operation
	vec3<T> operator/ (const T& a)
	{
		return vec3<T>(
			x / a,
			y / a,
			z / a
		);
	}

	vec3<T> operator* (const vec3<T>& a)
	{
		return vec3<T>(
			x * a.x,
			y * a.y,
			z * a.z
		);
	}

	// Scalar operation
	vec3<T> operator* (const T& a)
	{
		return vec3<T>(
			x * a,
			y * a,
			z * a
		);
	}

	friend std::ostream& operator<< (std::ostream& stream, const vec3<T>& a)
	{
		return stream << "(" << a.x << ", " << a.y << ", " << a.z << ")";
	}

	// Attributes

	union {
		struct { T x, y, z; };
		T _a[3];
	};

	int bounds = sizeof(T) * 3;
};

template<typename T>
struct vec4
{

	// Constructors 

	vec4(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}

	vec4(const vec4<T>& a) : x(a.x), y(a.y), z(a.z), w(a.w) {}

	// Scalar operation
	vec4(const T& a) : x(a), y(a), z(a), w(a) {}

	// Methods 

	T length()
	{
		return sqrt(
			x * x + 
			y * y + 
			z * z + 
			w * w
		);
	}

	vec4<T> normalized()
	{
		return vec4<T>(*this / length());
	}

	// Static methods

	static T dot(const vec4<T>& a, const vec4<T>& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	// Operator overloads

	T operator[](int index)
	{
		OUTOFBOUNDSCHECK(sizeof(T) * index, bounds);
		return _a[index];
	}

	vec4<T> operator+ (const vec4<T>& a)
	{
		return vec4<T>(
			x + a.x,
			y + a.y,
			z + a.z,
			w + a.w
		);
	}

	// Scalar operation
	vec4<T> operator+ (const T& a)
	{
		return vec4<T>(
			x + a,
			y + a,
			z + a,
			w + a
		);
	}

	vec4<T> operator- (const vec4<T>& a)
	{
		return vec4<T>(
			x - a.x,
			y - a.y,
			z - a.z,
			w - a.w
		);
	}

	// Scalar operation
	vec4<T> operator- (const T& a)
	{
		return vec4<T>(
			x - a,
			y - a,
			z - a,
			w - a
		);
	}

	vec4<T> operator/ (const vec4<T>& a)
	{
		return vec4<T>(
			x / a.x,
			y / a.y,
			z / a.z,
			w / a.w
		);
	}

	// Scalar operation
	vec4<T> operator/ (const T& a)
	{
		return vec4<T>(
			x / a,
			y / a,
			z / a,
			w / a
		);
	}

	vec4<T> operator* (const vec4<T>& a)
	{
		return vec4<T>(
			x * a.x,
			y * a.y,
			z * a.z,
			w * a.w
		);
	}

	// Scalar operation
	vec4<T> operator* (const T& a)
	{
		return vec4<T>(
			x * a,
			y * a,
			z * a,
			w * a
		);
	}

	friend std::ostream& operator<< (std::ostream& stream, const vec4<T>& a)
	{
		return stream << "(" << a.x << ", " << a.y << ", " << a.z << ", " << a.w << ")";
	}

	// Attributes

	union {
		struct { T x, y, z, w; };
		T _a[4];
	};

	int bounds = sizeof(T) * 4;
};


typedef vec2<int> vec2i;
typedef vec2<float> vec2f;
typedef vec2<double> vec2d;

typedef vec3<int> vec3i;
typedef vec3<float> vec3f;
typedef vec3<double> vec3d;

typedef vec4<int> vec4i;
typedef vec4<float> vec4f;
typedef vec4<double> vec4d;


template <typename T>
struct mat2
{
	// Constructors

	mat2<T>(
		T x1, T y1,
		T x2, T y2
	) : x(x1, x2), y(y1, y2) {}

	mat2(const vec2<T>& _x, const vec2<T>& _y) : x(_x), y(_y) {}

	mat2(const mat2<T>& a) : x(a.x), y(a.y) {}

	// Scalar operation
	mat2(const T& a) : x(a), y(a) {}


	// Operator overloads

	mat2<T> operator+ (const mat2<T>& a)
	{
		return mat2<T>(
			x.x + a.x.x, y.x + a.y.x,
			x.y + a.x.y, y.y + a.y.y
		);
	}

	// Scalar operation
	mat2<T> operator+ (const T& a)
	{
		return mat2<T>(
			x.x + a, y.x + a,
			x.y + a, y.y + a
		);
	}

	mat2<T> operator- (const mat2<T>& a)
	{
		return mat2<T>(
			x.x - a.x.x, y.x - a.y.x,
			x.y - a.x.y, y.y - a.y.y
			);
	}

	// Scalar operation
	mat2<T> operator- (const T& a)
	{
		return mat2<T>(
			x.x - a, y.x - a,
			x.y - a, y.y - a
		);
	}

	mat2<T> operator* (const mat2<T>& a)
	{
		// Column major product

		return mat2<T>(
			(x.x * a.x.x + x.y * a.y.x), (y.x * a.x.x + y.y * a.y.x), 
			(x.x * a.x.y + x.y * a.y.y), (y.x * a.x.y + y.y * a.y.y)
		);
	}

	// Scalar operation
	mat2<T> operator* (const T& a)
	{
		// Column major product

		return mat2<T>(
			x.x * a, y.x * a,
			x.y * a, y.y * a
		);
	}

	// Scalar operation
	mat2<T> operator/ (const T& a)
	{
		// Column major product

		return mat2<T>(
			x.x / a, y.x / a,
			x.y / a, y.y / a
			);
	}

	bool operator== (const mat2<T>& a) const
	{
		return (x == a.x) && (y == a.y);
	}

	vec2<T> operator[](int index)
	{
		OUTOFBOUNDSCHECK(sizeof(T) * index, bounds / 2);
		return _v[index];
	}

	friend std::ostream& operator<< (std::ostream& stream, const mat2<T>& a)
	{
		return stream << "[" << a.x << ", " << a.y << "]";
	}

	// Attributes

	union {
		struct { vec2<T> x, y; };
		vec2<T> _v[2];
	};

	int bounds = sizeof(T) * 4;
};

template <typename T>
struct mat3
{
	// Constructors
	
	mat3(
		T x1, T y1, T z1,
		T x2, T y2, T z2,
		T x3, T y3, T z3
	) : x(x1, x2, x3), y(y1, y2, y3), z(z1, z2, z3) {}

	mat3(vec3<T> _x, vec3<T> _y, vec3<T> _z) : x(_x), y(_y), z(_z) {}

	mat3(const mat3<T>& a) : x(a.x), y(a.y), z(a.z) {}

	// Scalar operation
	mat3(const T& a) : x(a), y(a), z(a) {}


	// Operator overloads

	mat3<T> operator+ (const mat3<T>& a)
	{
		return mat3<T>(
			x.x + a.x.x, y.x + a.y.x, + z.x + a.z.x,
			x.y + a.x.y, y.y + a.y.y, + z.y + a.z.y,
			x.z + a.x.z, y.z + a.y.z, + z.z + a.z.z
		);
	}

	vec3<T> operator[](int index)
	{
		OUTOFBOUNDSCHECK(sizeof(T) * index, bounds / 3);
		return _v[index];
	}

	friend std::ostream& operator<< (std::ostream& stream, const mat3<T>& a)
	{
		return stream << "[" << a.x << ", " << a.y << ", " << a.z << "]";
	}

	// Attributes

	union {
		struct { vec3<T> x, y, z; };
		vec3<T> _v[3];
	};

	int bounds = sizeof(T) * 6;
};

typedef mat2<int> mat2i;
typedef mat2<float> mat2f;
typedef mat2<double> mat2d;

typedef mat3<int> mat3i;
typedef mat3<float> mat3f;
typedef mat3<double> mat3d;

struct Eangles
{
	vec3f vector()
	{
		return vec3f(cos(y), sin(p), (sin(y) * cos(p)));
	}

	void normalize()
	{
		if (p > 89)
			p = 89;

		else if (p < -89)
			p = -89;

		while (y < -180)
			y += 360;

		while (y > 180)
			y -= 360;
	}

	float p; float y; float r;
};