#include "vec2.h"

Vec2 Vec2::operator=(const Vec2& other)
{
	this->m_x = other.m_x;
	this->m_y = other.m_y;

	return *this;
}

Vec2 Vec2::operator+(const Vec2& other) const {
	return Vec2(this->m_x + other.m_x, this->m_y + other.m_y);
}

Vec2 Vec2::operator-(const Vec2& other) const {
	return Vec2(this->m_x - other.m_x, this->m_y - other.m_y);
}

Vec2 operator*(const Vec2& vec, double c) {
	return Vec2(c * vec.m_x, c * vec.m_y);
}

Vec2 operator*(double c, const Vec2& vec) {
	return vec * c;
}