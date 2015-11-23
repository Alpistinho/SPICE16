#include "stdafx.h"
#include "CurrentControlledCurrentSource.h"


CurrentControlledCurrentSource::CurrentControlledCurrentSource(void)
{
}

CurrentControlledCurrentSource::CurrentControlledCurrentSource(Node *n1, Node *n2, Node *n3, Node *n4, Branch *b1, double gain, unsigned long newKey) {
	node1 = n1;
	node2 = n2;
	node3 = n3;
	node4 = n4;
	branch1 = b1;
	value = gain;
	key = newKey;
}

CurrentControlledCurrentSource::~CurrentControlledCurrentSource(void)
{
}

ComponentType CurrentControlledCurrentSource::getComponentType() {
	return ComponentType::CurrentControlledCurrentSource;
}

void CurrentControlledCurrentSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {

	(*equationSystem)[node1->getNodeNumber()][branch1->getBranchNumber()] += value;	
	(*equationSystem)[node2->getNodeNumber()][branch1->getBranchNumber()] -= value;

	(*equationSystem)[node3->getNodeNumber()][branch1->getBranchNumber()] += 1;
	(*equationSystem)[node4->getNodeNumber()][branch1->getBranchNumber()] -= 1;
	(*equationSystem)[branch1->getBranchNumber()][node3->getNodeNumber()] -= 1;
	(*equationSystem)[branch1->getBranchNumber()][node4->getNodeNumber()] += 1;

}