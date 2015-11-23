#include "stdafx.h"
#include "VoltageControlledCurrentSource.h"


VoltageControlledCurrentSource::VoltageControlledCurrentSource(void)
{
}

VoltageControlledCurrentSource::VoltageControlledCurrentSource(Node *n1, Node *n2, Node *n3, Node *n4, double gain) {
	node1 = n1;
	node2 = n2;
	node3 = n3;
	node4 = n4;
	value = gain;
}

VoltageControlledCurrentSource::~VoltageControlledCurrentSource(void)
{
}

ComponentType VoltageControlledCurrentSource::getComponentType() {
	return ComponentType::VoltageControlledCurrentSource;
}

void VoltageControlledCurrentSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {

	(*equationSystem)[node3->getNodeNumber()][node1->getNodeNumber()] += value;	
	(*equationSystem)[node4->getNodeNumber()][node1->getNodeNumber()] -= value;
	(*equationSystem)[node3->getNodeNumber()][node2->getNodeNumber()] -= value;	
	(*equationSystem)[node4->getNodeNumber()][node2->getNodeNumber()] += value;

}