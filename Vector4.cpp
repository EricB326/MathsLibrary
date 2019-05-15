#include "Vector4.h"
#include <cassert>
#include <cmath>

//** CONSTRUCTORS **//
Vector4::Vector4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f)
{}

Vector4::Vector4(const float a_x, const float a_y, const float a_z, const float a_w = 1.0f)
	: x(a_x), y(a_y), z(a_z), w(a_w)
{}

//** SUBSCRIPT **//
float& Vector4::operator[] (const int a_index)
{
	_STL_ASSERT((a_index >= 0) && (a_index < 2), "ERROR! Vector 2 index out of range.");
	return data[a_index];
}

// ** OPERATOR CASTING **//
Vector4::operator float* ()
{
	return data;
}

Vector4::operator const float* () const
{
	return data;
}

//** CONSTRUCTION ZONE **//
Vector4 Vector4::operator+ (const Vector4& a_rhs) const
{
	return Vector4(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z, w + a_rhs.w);
}

Vector4 Vector4::operator- (const Vector4& a_rhs) const
{
	return Vector4(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z, w - a_rhs.w);
}

Vector4 Vector4::operator* (const float a_rhs) const
{
	return Vector4(x * a_rhs, y * a_rhs, z * a_rhs, w * a_rhs);
}

Vector4 Vector4::operator/ (const float a_rhs) const
{
	_STL_ASSERT((a_rhs > 0), "ERROR! Division by 0 detected.");
	return Vector4(x / a_rhs, y / a_rhs, z / a_rhs, w / a_rhs);
}

Vector4 operator* (const float a_lhs, const Vector4& a_rhs)
{
	return a_rhs * a_lhs;
}

//** CORRESPONDING op= **//
Vector4& Vector4::operator+= (const Vector4& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

Vector4& Vector4::operator-= (const Vector4& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}

Vector4& Vector4::operator*= (const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

Vector4& Vector4::operator/= (const float a_rhs)
{
	_STL_ASSERT((a_rhs > 0), "ERROR! Division by 0 detected.");
	*this = *this / a_rhs;
	return *this;
}

bool Vector4::operator== (const Vector4& a_rhs) const
{
	return ((x == a_rhs.x) && (y == a_rhs.y) && (z == a_rhs.z) && (w == a_rhs.w));
}

//** UTILIZATION **//
float Vector4::square_magnitude() const
{
	return (x * x) + (y * y) + (z * z);
}

float Vector4::magnitude() const
{
	return sqrt(square_magnitude());
}

void Vector4::normalise()
{
	*this /= magnitude();
}

Vector4 Vector4::normalised() const
{
	return *this / magnitude();
}

float Vector4::dot(const Vector4& a_vec4) const
{
	return (x * a_vec4.x) + (y * a_vec4.y) + (z * a_vec4.z);
}

float Vector4::dot(const Vector4& a_vec4_1, const Vector4& a_vec4_2)
{
	return a_vec4_1.dot(a_vec4_2);
}

Vector4 Vector4::cross(const Vector4& a_vec4) const
{
	return { (y * a_vec4.z) - (z * a_vec4.y),
			 (z * a_vec4.x) - (x * a_vec4.z),
			 (x * a_vec4.y) - (y * a_vec4.x),
			 (w) };
}

Vector4 Vector4::cross(const Vector4& a_vec4_1, const Vector4& a_vec4_2)
{
	return a_vec4_1.cross(a_vec4_2);
}