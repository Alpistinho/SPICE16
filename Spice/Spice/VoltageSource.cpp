#include "stdafx.h"
#include "VoltageSource.h"


VoltageSource::VoltageSource(void)
{
}

VoltageSource::VoltageSource(Node* n1, Node* n2, double current, double phase) {
	node1 = n1;
	node2 = n2;
	value = std::complex<double>(current*std::cos(phase), current*std::sin(phase));
}

VoltageSource::~VoltageSource(void)
{
}

void VoltageSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {

	unsigned long columns = (*equationSystem)[0].size(); // number of columns the matrix has

	(*equationSystem)[branch1->getBranchNumber()][node1->getNodeNumber()] += 1;
	(*equationSystem)[branch1->getBranchNumber()][node2->getNodeNumber()] -= 1;

	(*equationSystem)[node1->getNodeNumber()][branch1->getBranchNumber()] += 1;
	(*equationSystem)[node2->getNodeNumber()] [branch1->getBranchNumber()] -= 1;

	(*equationSystem)[branch1->getBranchNumber()][columns] += value;

}
