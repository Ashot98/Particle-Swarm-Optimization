#pragma once
#include <utility>
#include "vec2.h"

using Func = double (*)(const Vec2&);

class Agent
{
public:
	Agent(Func f, Vec2* bestGroup, double w = 0.9, unsigned c1 = 2, unsigned c2 = 2);

	void init();
	void move();
	void update();

	Vec2 getPosition() { return m_position; }
	Vec2 getBestSelf() { return m_bestSelf; }
private:
	Vec2 m_position;
	Vec2 m_velocity;
	Vec2 m_bestSelf;
	Vec2* m_bestGroup;

	Func m_func;

	double m_w;
	unsigned m_c1;
	unsigned m_c2;
};

