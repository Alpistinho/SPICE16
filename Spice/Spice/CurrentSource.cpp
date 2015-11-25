#include "stdafx.h"
#include "CurrentSource.h"


CurrentSource::CurrentSource(void)
{
}

CurrentSource::CurrentSource(Node* n1, Node* n2, double current, double phase, unsigned long newKey) {
	node1 = n1;
	node2 = n2;
	value = std::complex<double>(current*std::cos(phase), current*std::sin(phase));
	key = newKey;
}

CurrentSource::~CurrentSource(void)
{
}

ComponentType CurrentSource::getComponentType() {
	return ComponentType::CurrentSource;
}

void CurrentSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {
	unsigned long columns = (*equationSystem)[0].size(); // number of columns the matrix has
	(*equationSystem)[node1->getNodeNumber()][columns-1] += value;
	(*equationSystem)[node2->getNodeNumber()][columns-1] -= value;
}