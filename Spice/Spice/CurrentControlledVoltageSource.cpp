#include "stdafx.h"
#include "CurrentControlledVoltageSource.h"

namespace spiceSimulator {

	CurrentControlledVoltageSource::CurrentControlledVoltageSource(void)
	{
	}

	CurrentControlledVoltageSource::CurrentControlledVoltageSource(Node *n1, Node *n2, Node *n3, Node *n4, Branch *b1, double gain, unsigned long newKey) {
		node1 = n1;
		node2 = n2;
		node3 = n3;
		node4 = n4;
		value = gain;
		branch1 = b1;
		key = newKey;
	}

	CurrentControlledVoltageSource::~CurrentControlledVoltageSource(void)
	{
	}

	ComponentType CurrentControlledVoltageSource::getComponentType() {
		return ComponentType::CurrentControlledVoltageSource;
	}

	void CurrentControlledVoltageSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {

		(*equationSystem)[node1->getNodeNumber()][branch1->getBranchNumber()] += 1;	
		(*equationSystem)[node2->getNodeNumber()][branch1->getBranchNumber()] -= 1;
		(*equationSystem)[node3->getNodeNumber()][branch2->getBranchNumber()] += 1;	
		(*equationSystem)[node4->getNodeNumber()][branch2->getBranchNumber()] -= 1;

		(*equationSystem)[branch1->getBranchNumber()][node1->getNodeNumber()] -= 1;
		(*equationSystem)[branch1->getBranchNumber()][node2->getNodeNumber()] += 1;
		(*equationSystem)[branch2->getBranchNumber()][node3->getNodeNumber()] -= 1;
		(*equationSystem)[branch2->getBranchNumber()][node4->getNodeNumber()] += 1;

		(*equationSystem)[branch2->getBranchNumber()][branch1->getBranchNumber()] += value;

	}
}