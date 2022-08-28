#pragma once
struct Vec2
{
	double m_x;
	double m_y;

	Vec2() : m_x(0), m_y(0) {}
	Vec2(double x, double y) : m_x(x), m_y(y) {}
	Vec2(const Vec2& other) : m_x(other.m_x), m_y(other.m_y) {}

	Vec2 operator=(const Vec2& other);

	Vec2 operator+(const Vec2& other) const;
	Vec2 operator-(const Vec2& other) const;
};

Vec2 operator*(const Vec2& vec, double c);

Vec2 operator*(double c, const Vec2& vec);