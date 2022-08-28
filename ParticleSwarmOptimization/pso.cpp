#include "pso.h"

PSO::PSO(Func f, unsigned n, double w, unsigned c1, unsigned c2)
{
	srand(time(NULL));
	m_func = f;

	double x = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) * 200 - 100; // (-100, 100]
	double y = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) * 200 - 100; // (-100, 100]
	m_bestGroup = new Vec2(x, y);

	m_agents.reserve(n);
	for (size_t i = 0; i < n; ++i) {
		m_agents.emplace_back(Agent(f, m_bestGroup, w, c1, c2));
	}
}

PSO::~PSO()
{
	if(m_agents.size() != 0)
		delete m_bestGroup;
}

void PSO::optimize(int iters)
{
	for (size_t iter = 0; iter < iters; ++iter) {
		const auto size = m_agents.size();
		for (size_t i = 0; i < size; ++i) {
			m_agents[i].move();
			m_agents[i].update();
		}
		std::cout << "After iter " << iter+1 << " the best value is " << m_func(*m_bestGroup) << std::endl;
	}
}
