#include "stdafx.h"
#include "OpAmp.h"


OpAmp::OpAmp(void)
{
}


OpAmp::~OpAmp(void)
{
}

OpAmp::OpAmp(Node *n1, Node *n2, Node *n3, Node *n4) {
	node1 = n1;
	node2 = n2;
	node3 = n3;
	node4 = n4;
}

ComponentType OpAmp::getComponentType() {
	return ComponentType::OpAmp;
}

void OpAmp::getFrequencyStamp(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {

	(*equationSystem)[node1->getNodeNumber()][branch1->getBranchNumber()] += 1;	
	(*equationSystem)[node2->getNodeNumber()][branch1->getBranchNumber()] -= 1;
	(*equationSystem)[branch1->getBranchNumber()][node3->getNodeNumber()] += 1;	
	(*equationSystem)[branch1->getBranchNumber()][node4->getNodeNumber()] -= 1;

}