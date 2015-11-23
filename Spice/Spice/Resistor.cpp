#include "stdafx.h"
#include "Resistor.h"


Resistor::Resistor(void)
{
}

Resistor::Resistor(Node* n1, Node* n2, double R)
{
	node1 = n1;
	node2 = n2;
	value = R;
}

Resistor::~Resistor(void)
{
}


ComponentType Resistor::getComponentType() {
	return ComponentType::Resistor;
}

void Resistor::getFrequencyStamp(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {
	(*equationSystem)[node1->getNodeNumber()][node1->getNodeNumber()] += 1/value;
	(*equationSystem)[node1->getNodeNumber()][node2->getNodeNumber()] -= 1/value;
	(*equationSystem)[node2->getNodeNumber()][node1->getNodeNumber()] -= 1/value;
	(*equationSystem)[node2->getNodeNumber()][node2->getNodeNumber()] += 1/value;
}