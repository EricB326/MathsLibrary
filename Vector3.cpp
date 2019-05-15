#include "Vector3.h"
#include <cassert>
#include <cmath>

//** CONSTRUCTORS **//
Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f)
{}

Vector3::Vector3(const float a_x, const float a_y, const float a_z)
	: x(a_x), y(a_y), z(a_z)
{}

float& Vector3::operator[] (const int a_index)
{
	//_STL_ASSERT((a_index >= 0) && (a_index < 2), "ERROR! Vector 3 index out of range.");
	return data[a_index];
}

//** SUBSCRIPT **//
Vector3::operator float* ()
{
	return data;
}

Vector3::operator const float* () const
{
	return data;
}

//** CONSTRUCTION ZONE **//
Vector3 Vector3::operator+ (const Vector3& a_rhs) const
{
	return Vector3(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
}

Vector3 Vector3::operator- (const Vector3& a_rhs) const
{
	return Vector3(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
}

Vector3 Vector3::operator* (const float a_rhs) const
{
	return Vector3(x * a_rhs, y * a_rhs, z * a_rhs);
}

Vector3 Vector3::operator/ (const float a_rhs) const
{
	_STL_ASSERT((a_rhs > 0), "ERROR! Devision by 0 detected.");
	return Vector3(x / a_rhs, y / a_rhs, z / a_rhs);
}

Vector3 operator* (const float a_lhs, const Vector3& a_rhs)
{
	return a_rhs * a_lhs;
}

//** CORRESPONDING op= **//
Vector3& Vector3::operator+= (const Vector3& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

Vector3& Vector3::operator-= (const Vector3& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}

Vector3& Vector3::operator*= (const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

Vector3& Vector3::operator/= (const float a_rhs)
{
	_STL_ASSERT((a_rhs > 0), "ERROR! Devision by 0 detected.");
	*this = *this / a_rhs;
	return *this;
}

bool Vector3::operator== (const Vector3& a_rhs) const
{
	return ((x == a_rhs.x) && (y == a_rhs.y) && (z == a_rhs.z));
}

//** UTILIZATION **//
float Vector3::square_magnitude() const
{
	return (x * x) + (y * y) + (z * z);
}

float Vector3::magnitude() const
{
	return sqrt(square_magnitude());
}

void Vector3::normalise()
{
	*this /= magnitude();
}

Vector3 Vector3::normalised() const
{
	return *this / magnitude();
}

float Vector3::dot(const Vector3& a_vec3) const
{
	return (x * a_vec3.x) + (y * a_vec3.y) + (z * a_vec3.z);
}

float Vector3::dot(const Vector3& a_vec3_1, const Vector3& a_vec3_2)
{
	return a_vec3_1.dot(a_vec3_2);
}

Vector3 Vector3::cross(const Vector3& a_vec3) const
{
	return { (y * a_vec3.z) - (z * a_vec3.y),
			 (z * a_vec3.x) - (x * a_vec3.z),
			 (x * a_vec3.y) - (y * a_vec3.x) };
}

Vector3 Vector3::cross(const Vector3& a_vec3_1, const Vector3& a_vec3_2)
{
	return a_vec3_1.cross(a_vec3_2);
}