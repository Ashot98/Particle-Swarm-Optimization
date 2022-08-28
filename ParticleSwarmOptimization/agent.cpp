#include "agent.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Agent::Agent(Func f, Vec2* bestGroup, double w, unsigned c1, unsigned c2)
{
	this->m_func = f;
	this->m_w = w;
	this->m_c1 = c1;
	this->m_c2 = c2;
	
	m_bestGroup = bestGroup;

	init();
}

void Agent::init()
{
	double x = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) * 200 - 100; // (-100, 100]
	double y = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) * 200 - 100; // (-100, 100]

	this->m_position.m_x = x;
	this->m_position.m_y = y;

	x = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) * 200 - 100; // (-100, 100]
	y = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) * 200 - 100; // (-100, 100]

	this->m_velocity.m_x = x;
	this->m_velocity.m_y = y;

	this->m_bestSelf = this->m_position;
	if (m_func(m_bestSelf) < m_func(*m_bestGroup)) {
		*m_bestGroup = m_bestSelf;
	}
}

void Agent::move()
{
	double r1 = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)); // (0, 1]
	double r2 = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)); // (0, 1]
	m_velocity = m_w * m_velocity + m_c1 * r1 * (m_bestSelf - m_position) + m_c2 * r2 * (*m_bestGroup - m_position);

	m_position = m_position + m_velocity;
}

void Agent::update()
{
	if (m_func(m_position) < m_func(m_bestSelf)) {
		m_bestSelf = m_position;
		if (m_func(m_bestSelf) < m_func(*m_bestGroup)) {
			*m_bestGroup = m_bestSelf;
		}
	}
}
