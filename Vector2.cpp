#include "Vector2.h"
#include <cassert>
#include <cmath>

Vector2::Vector2() : x(0.0f), y(0.0f)
{}

Vector2::Vector2(const float a_x, const float a_y) : x(a_x), y(a_y)
{}

float& Vector2::operator[] (const int a_index)
{
	_STL_ASSERT((a_index >= 0) && (a_index < 2), "ERROR! Vector 2 index out of range.");
	return data[a_index];
}

Vector2::operator float* () 
{ 
	return data; 
}

Vector2::operator const float* () const
{
	return data; 
}

Vector2 Vector2::operator+ (const Vector2& a_rhs) const 
{ 
	return Vector2(x + a_rhs.x, y + a_rhs.y);
} 

Vector2 Vector2::operator- (const Vector2& a_rhs) const
{
	return Vector2(x - a_rhs.x, y - a_rhs.y);
}

Vector2 Vector2::operator* (const float a_rhs) const
{ 
	return Vector2(x * a_rhs, y * a_rhs);
}

Vector2 Vector2::operator/ (const float a_rhs) const
{
	_STL_ASSERT((a_rhs > 0), "ERROR! Devision by 0 detected.");
	return Vector2(x / a_rhs, y / a_rhs);
}

Vector2 operator* (const float a_lhs, const Vector2& a_rhs)
{
	return a_rhs * a_lhs;
}

Vector2& Vector2::operator+= (const Vector2& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

Vector2& Vector2::operator-= (const Vector2& a_rhs)
{ 
	*this = *this - a_rhs;
	return *this; 
}

Vector2& Vector2::operator*= (const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

Vector2& Vector2::operator/= (const float a_rhs)
{ 
	_STL_ASSERT((a_rhs > 0), "ERROR! Devision by 0 detected.");
	*this = *this / a_rhs;
	return *this; 
}

bool Vector2::operator== (const Vector2& a_rhs) const
{
	return ((x == a_rhs.x) && (y == a_rhs.y));
}

float Vector2::square_magnitude() const
{
	return (x * x) + (y * y);
}

float Vector2::magnitude() const
{
	return sqrt(square_magnitude());
}

void Vector2::normalise()
{
	*this /= magnitude();
}

Vector2 Vector2::normalised() const
{
	return *this / magnitude();
}

float Vector2::dot(const Vector2& a_vec2) const
{
	return (x * a_vec2.x) + (y * a_vec2.y);
}

Vector2 Vector2::right() const
{
	return { y, -x };
}

float Vector2::dot(const Vector2& a_vec2_1, const Vector2& a_vec2_2)
{
	return a_vec2_1.dot(a_vec2_2);
}