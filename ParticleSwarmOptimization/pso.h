#pragma once
#include <vector>
#include <iostream>
#include "agent.h"

class PSO
{
public:
	PSO(Func f, unsigned n = 10, double w = 0.9, unsigned c1 = 2, unsigned c2 = 2);
	~PSO();

	void optimize(int iters = 10);
private:
	std::vector<Agent> m_agents;
	Func m_func;
	Vec2* m_bestGroup = nullptr;
};

