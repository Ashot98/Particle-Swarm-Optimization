#include <iostream>
#include "pso.h"

double f(const Vec2& coords)
{
	return coords.m_x * coords.m_x + coords.m_y * coords.m_y;
}

int main() {
	PSO pso(f, 100);
	pso.optimize(5000);

	return 0;
}