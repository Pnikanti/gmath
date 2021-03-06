#pragma once

#include <cmath>
#include <iostream>

/*
	Stupidly simple maths library.
*/


// Globals

// Approximate equality for floating point numbers
template <typename T>
bool APPROXEQ(T a, T b)
{
	T x = abs(a);
	T y = abs(b);
	T dxy = abs(a - b);

	if (a == b)
		return true;
	else if (a == 0 || b == 0 || dxy < std::numeric_limits<T>::min())
		return dxy < (std::numeric_limits<T>::epsilon() * std::numeric_limits<T>::min());
	else
		return dxy / (x + y) < std::numeric_limits<T>::epsilon();
}
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

	T length() const
	{
		return sqrt(
			x * x +
			y * y
		);
	}

	vec2<T> normalized() const
	{
		return vec2<T>(*this / length());
	}

	// Static methods

	static T dot(const vec2<T>& a, const vec2<T>& b)
	{
		return a.x * b.x + a.y * b.y;
	}

	// Operator overloads

	T operator[](int index) const
	{
		OUTOFBOUNDSCHECK(sizeof(T) * index, bounds);
		return _a[index];
	}


	bool operator== (const vec2<T>& a) const
	{
		return APPROXEQ(x, a.x) && APPROXEQ(y, a.y);
	}

	vec2<T> operator+ (const vec2<T>& a) const
	{
		return vec2<T>(
			x + a.x,
			y + a.y
		);
	}

	// Scalar operation
	vec2<T> operator+ (const T& a) const
	{
		return vec2<T>(
			x + a,
			y + a
		);
	}

	vec2<T> operator- (const vec2<T>& a) const
	{
		return vec2<T>(
			x - a.x,
			y - a.y
		);
	}

	// Scalar operation
	vec2<T> operator- (const T& a) const
	{
		return vec2<T>(
			x - a,
			y - a
		);
	}

	vec2<T> operator/ (const vec2<T>& a) const
	{
		return vec2<T>(
			x / a.x, 
			y / a.y
		);
	}

	// Scalar operation
	vec2<T> operator/ (const T& a) const
	{
		return vec2<T>(
			x / a,
			y / a
		);
	}

	vec2<T> operator* (const vec2<T>& a) const
	{
		return vec2<T>(
			x * a.x,
			y * a.y
		);
	}

	// Scalar operation
	vec2<T> operator* (const T& a) const
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

	T length() const
	{
		return sqrt(
			x * x +
			y * y +
			z * z
		);
	}

	vec3<T> normalized() const
	{
		return vec3<T>(*this / length());
	}

	// Static methods

	static T dot(const vec3<T>& a, const vec3<T>& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	// Operator overloads

	T operator[](int index) const
	{
		OUTOFBOUNDSCHECK(sizeof(T) * index, bounds);
		return _a[index];
	}

	bool operator== (const vec3<T>& a) const
	{
		return APPROXEQ(x, a.x) && APPROXEQ(y, a.y) && APPROXEQ(z, a.z);
	}

	vec3<T> operator+ (const vec3<T>& a) const
	{
		return vec3<T>(
			x + a.x,
			y + a.y,
			z + a.z
		);
	}

	// Scalar operation
	vec3<T> operator+ (const T& a) const
	{
		return vec3<T>(
			x + a,
			y + a,
			z + a
		);
	}

	vec3<T> operator- (const vec3<T>& a) const
	{
		return vec3<T>(
			x - a.x,
			y - a.y,
			z - a.z
		);
	}

	// Scalar operation
	vec3<T> operator- (const T& a) const
	{
		return vec3<T>(
			x - a, 
			y - a,
			z - a
		);
	}

	vec3<T> operator/ (const vec3<T>& a) const
	{
		return vec3<T>(
			x / a.x,
			y / a.y, 
			z / a.z
		);
	}

	// Scalar operation
	vec3<T> operator/ (const T& a) const
	{
		return vec3<T>(
			x / a,
			y / a,
			z / a
		);
	}

	vec3<T> operator* (const vec3<T>& a) const
	{
		return vec3<T>(
			x * a.x,
			y * a.y,
			z * a.z
		);
	}

	// Scalar operation
	vec3<T> operator* (const T& a) const
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

	T length() const
	{
		return sqrt(
			x * x + 
			y * y + 
			z * z + 
			w * w
		);
	}

	vec4<T> normalized() const
	{
		return vec4<T>(*this / length());
	}

	// Static methods

	static T dot(const vec4<T>& a, const vec4<T>& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	// Operator overloads

	T operator[](int index) const
	{
		OUTOFBOUNDSCHECK(sizeof(T) * index, bounds);
		return _a[index];
	}

	bool operator== (const vec4<T>& a) const
	{
		return APPROXEQ(x, a.x) && APPROXEQ(y, a.y) && APPROXEQ(z, a.z) && APPROXEQ(w, a.w);
	}

	vec4<T> operator+ (const vec4<T>& a) const
	{
		return vec4<T>(
			x + a.x,
			y + a.y,
			z + a.z,
			w + a.w
		);
	}

	// Scalar operation
	vec4<T> operator+ (const T& a) const
	{
		return vec4<T>(
			x + a,
			y + a,
			z + a,
			w + a
		);
	}

	vec4<T> operator- (const vec4<T>& a) const
	{
		return vec4<T>(
			x - a.x,
			y - a.y,
			z - a.z,
			w - a.w
		);
	}

	// Scalar operation
	vec4<T> operator- (const T& a) const
	{
		return vec4<T>(
			x - a,
			y - a,
			z - a,
			w - a
		);
	}

	vec4<T> operator/ (const vec4<T>& a) const
	{
		return vec4<T>(
			x / a.x,
			y / a.y,
			z / a.z,
			w / a.w
		);
	}

	// Scalar operation
	vec4<T> operator/ (const T& a) const
	{
		return vec4<T>(
			x / a,
			y / a,
			z / a,
			w / a
		);
	}

	vec4<T> operator* (const vec4<T>& a) const
	{
		return vec4<T>(
			x * a.x,
			y * a.y,
			z * a.z,
			w * a.w
		);
	}

	// Scalar operation
	vec4<T> operator* (const T& a) const
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

	mat2<T> operator+ (const mat2<T>& a) const
	{
		return mat2<T>(
			x.x + a.x.x, y.x + a.y.x,
			x.y + a.x.y, y.y + a.y.y
		);
	}

	// Scalar operation
	mat2<T> operator+ (const T& a) const
	{
		return mat2<T>(
			x.x + a, y.x + a,
			x.y + a, y.y + a
		);
	}

	mat2<T> operator- (const mat2<T>& a) const
	{
		return mat2<T>(
			x.x - a.x.x, y.x - a.y.x,
			x.y - a.x.y, y.y - a.y.y
			);
	}

	// Scalar operation
	mat2<T> operator- (const T& a) const
	{
		return mat2<T>(
			x.x - a, y.x - a,
			x.y - a, y.y - a
		);
	}

	mat2<T> operator* (const mat2<T>& a) const
	{
		// Column major product

		return mat2<T>(
			(x.x * a.x.x + x.y * a.y.x), (y.x * a.x.x + y.y * a.y.x), 
			(x.x * a.x.y + x.y * a.y.y), (y.x * a.x.y + y.y * a.y.y)
		);
	}

	// Scalar operation
	mat2<T> operator* (const T& a) const
	{
		return mat2<T>(
			x.x * a, y.x * a,
			x.y * a, y.y * a
		);
	}

	// Scalar operation
	mat2<T> operator/ (const T& a) const
	{
		return mat2<T>(
			x.x / a, y.x / a,
			x.y / a, y.y / a
			);
	}

	bool operator== (const mat2<T>& a) const
	{
		return (x == a.x) && (y == a.y);
	}

	vec2<T> operator[](int index) const
	{
		OUTOFBOUNDSCHECK(sizeof(T) * index, bounds / 4);
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

	mat3<T> operator+ (const mat3<T>& a) const
	{
		return mat3<T>(
			x.x + a.x.x, y.x + a.y.x, z.x + a.z.x,
			x.y + a.x.y, y.y + a.y.y, z.y + a.z.y,
			x.z + a.x.z, y.z + a.y.z, z.z + a.z.z
		);
	}

	// Scalar operation
	mat3<T> operator+ (const T& a) const
	{
		return mat3<T>(
			x.x + a, y.x + a, z.x + a,
			x.y + a, y.y + a, z.y + a,
			x.z + a, y.z + a, z.z + a
		);
	}

	mat3<T> operator- (const mat3<T>& a) const
	{
		return mat3<T>(
			x.x - a.x.x, y.x - a.y.x, z.x - a.z.x,
			x.y - a.x.y, y.y - a.y.y, z.y - a.z.y,
			x.z - a.x.z, y.z - a.y.z, z.z - a.z.z
		);
	}

	// Scalar operation
	mat3<T> operator- (const T& a) const
	{
		return mat3<T>(
			x.x - a, y.x - a, z.x - a,
			x.y - a, y.y - a, z.y - a,
			x.z - a, y.z - a, z.z - a
		);
	}

	mat3<T> operator* (const mat3<T>& a) const
	{
		// Column major product

		return mat3<T>(
			(x.x * a.x.x + x.y * a.y.x + x.z * a.z.x), (y.x * a.x.x + y.y * a.y.x + y.z * a.z.x), (z.x * a.x.x + z.y * a.y.x + z.z * a.z.x),
			(x.x * a.x.y + x.y * a.y.y + x.z * a.z.y), (y.x * a.x.y + y.y * a.y.y + y.z * a.z.y), (z.x * a.x.y + z.y * a.y.y + z.z * a.z.y),
			(x.x * a.x.z + x.y * a.y.z + x.z * a.z.z), (y.x * a.x.z + y.y * a.y.z + y.z * a.z.z), (z.x * a.x.z + z.y * a.y.z + z.z * a.z.z)
		);
	}

	// Scalar operation
	mat3<T> operator* (const T& a) const
	{
		// Column major product

		return mat3<T>(
			x.x * a, y.x * a, z.x * a,
			x.y * a, y.y * a, z.y * a,
			x.z * a, y.z * a, z.z * a
		);
	}

	// Scalar operation
	mat3<T> operator/ (const T& a) const
	{
		return mat3<T>(
			x.x / a, y.x / a, z.x / a,
			x.y / a, y.y / a, z.y / a,
			x.z / a, y.z / a, z.z / a
		);
	}

	vec3<T> operator[](int index) const
	{
		OUTOFBOUNDSCHECK(sizeof(T) * index, bounds / 9);
		return _v[index];
	}


	bool operator== (const mat3<T>& a) const
	{
		return (x == a.x) && (y == a.y) && (z == a.z);
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

	int bounds = sizeof(T) * 9;
};

template <typename T>
struct mat4
{
	// Constructors

	mat4(
		T x1, T y1, T z1, T w1,
		T x2, T y2, T z2, T w2,
		T x3, T y3, T z3, T w3,
		T x4, T y4, T z4, T w4
	) : x(x1, x2, x3, x4), y(y1, y2, y3, y4), z(z1, z2, z3, z4) {}

	mat4(vec4<T> _x, vec4<T> _y, vec4<T> _z) : x(_x), y(_y), z(_z) {}

	mat4(const mat4<T>& a) : x(a.x), y(a.y), z(a.z), w(a.w) {}

	// Scalar operation
	mat4(const T& a) : x(a), y(a), z(a), w(a) {}


	// Operator overloads

	mat4<T> operator+ (const mat4<T>& a) const
	{
		return mat4<T>(
			x.x + a.x.x, y.x + a.y.x, z.x + a.z.x, w.x + a.w.x,
			x.y + a.x.y, y.y + a.y.y, z.y + a.z.y, w.y + a.w.y,
			x.z + a.x.z, y.z + a.y.z, z.z + a.z.z, w.z + a.w.z,
			x.w + a.x.w, w.z + a.y.w, z.w + a.z.w, w.w + a.w.w
		);
	}

	// Scalar operation
	mat4<T> operator+ (const T& a) const
	{
		return mat4<T>(
			x.x + a, y.x + a, z.x + a, w.x + a,
			x.y + a, y.y + a, z.y + a, w.y + a,
			x.z + a, y.z + a, z.z + a, w.z + a,
			x.w + a, y.w + a, z.w + a, w.w + a
		);
	}

	mat4<T> operator- (const mat4<T>& a) const
	{
		return mat4<T>(
			x.x - a.x.x, y.x - a.y.x, z.x - a.z.x, w.x - a.w.x,
			x.y - a.x.y, y.y - a.y.y, z.y - a.z.y, w.y - a.w.y,
			x.z - a.x.z, y.z - a.y.z, z.z - a.z.z, w.z - a.w.z,
			x.w - a.x.w, w.z - a.y.w, z.w - a.z.w, w.w - a.w.w
		);
	}

	// Scalar operation
	mat4<T> operator- (const T& a) const
	{
		return mat4<T>(
			x.x - a, y.x - a, z.x - a, w.x - a,
			x.y - a, y.y - a, z.y - a, w.y - a,
			x.z - a, y.z - a, z.z - a, w.z - a,
			x.w - a, y.w - a, z.w - a, w.w - a
		);
	}

	mat4<T> operator* (const mat4<T>& a) const
	{
		// Column major product

		return mat4<T>(
			(x.x * a.x.x + x.y * a.y.x + x.z * a.z.x + x.w * a.w.x), (y.x * a.x.x + y.y * a.y.x + y.z * a.z.x + y.w * a.w.x), (z.x * a.x.x + z.y * a.y.x + z.z * a.z.x + z.w * a.w.x), (w.x * a.x.x + w.y * a.y.x + w.z * a.z.x + w.w * a.w.x)
			(x.x * a.x.y + x.y * a.y.y + x.z * a.z.y + x.w * a.w.y), (y.x * a.x.y + y.y * a.y.y + y.z * a.z.y + y.w * a.w.y), (z.x * a.x.y + z.y * a.y.y + z.z * a.z.y + z.w * a.w.y), (w.x * a.x.y + w.y * a.y.y + w.z * a.z.y + w.w * a.w.y)
			(x.x * a.x.z + x.y * a.y.z + x.z * a.z.z + x.w * a.w.z), (y.x * a.x.z + y.y * a.y.z + y.z * a.z.z + y.w * a.w.z), (z.x * a.x.z + z.y * a.y.z + z.z * a.z.z + z.w * a.w.z), (w.x * a.x.z + w.y * a.y.z + w.z * a.z.z + w.w * a.w.z)
			(x.x * a.x.w + x.y * a.y.w + x.z * a.z.w + x.w * a.w.w), (y.x * a.x.w + y.y * a.y.w + y.z * a.z.w + y.w * a.w.w), (z.x * a.x.w + z.y * a.y.w + z.z * a.z.w + z.w * a.w.w), (w.x * a.x.w + w.y * a.y.w + w.z * a.z.w + w.w * a.w.w)
		);
	}

	// Scalar operation
	mat4<T> operator* (const T& a) const
	{
		// Column major product

		return mat4<T>(
			x.x * a, y.x * a, z.x * a, w.x * a,
			x.y * a, y.y * a, z.y * a, w.y * a,
			x.z * a, y.z * a, z.z * a, w.z * a,
			x.w * a, y.w * a, z.w * a, w.w * a
		);
	}

	// Scalar operation
	mat4<T> operator/ (const T& a) const
	{
		return mat4<T>(
			x.x / a, y.x / a, z.x / a, w.x / a,
			x.y / a, y.y / a, z.y / a, w.y / a,
			x.z / a, y.z / a, z.z / a, w.z / a,
			x.w / a, y.w / a, z.w / a, w.w / a
		);
	}

	vec4<T> operator[](int index) const
	{
		OUTOFBOUNDSCHECK(sizeof(T) * index, bounds / 16);
		return _v[index];
	}


	bool operator== (const mat4<T>& a) const
	{
		return (x == a.x) && (y == a.y) && (z == a.z) && (w == a.w);
	}


	friend std::ostream& operator<< (std::ostream& stream, const mat4<T>& a)
	{
		return stream << "[" << a.x << ", " << a.y << ", " << a.z << ", " << a.w << "]";
	}

	// Attributes

	union {
		struct { vec4<T> x, y, z, w; };
		vec4<T> _v[4];
	};

	int bounds = sizeof(T) * 16;
};

typedef mat2<int> mat2i;
typedef mat2<float> mat2f;
typedef mat2<double> mat2d;

typedef mat3<int> mat3i;
typedef mat3<float> mat3f;
typedef mat3<double> mat3d;

typedef mat4<int> mat4i;
typedef mat4<float> mat4f;
typedef mat4<double> mat4d;

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