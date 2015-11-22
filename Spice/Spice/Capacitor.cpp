#include "stdafx.h"
#include "Capacitor.h"


Capacitor::Capacitor(void)
{
}

Capacitor::Capacitor(Node *n1, Node *n2, double capacitance) {
	node1 = n1;
	node2 = n2;
	value = capacitance;
}

Capacitor::~Capacitor(void)
{
}

ComponentType Capacitor::getComponentType() {
	return ComponentType::Capacitor;
}

void Capacitor::getFrequencyStamp(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {
	(*equationSystem)[node1->getNodeNumber()][node1->getNodeNumber()] += std::complex<double>(0,	frequency*value);
	(*equationSystem)[node1->getNodeNumber()][node2->getNodeNumber()] -= std::complex<double>(0,	frequency*value);
	(*equationSystem)[node2->getNodeNumber()][node1->getNodeNumber()] -= std::complex<double>(0,	frequency*value);
	(*equationSystem)[node2->getNodeNumber()][node2->getNodeNumber()] += std::complex<double>(0,	frequency*value);
}