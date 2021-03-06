#include "stdafx.h"
#include "VoltageControlledVoltageSource.h"

namespace spiceSimulator {

	VoltageControlledVoltageSource::VoltageControlledVoltageSource(void)
	{
	}

	VoltageControlledVoltageSource::VoltageControlledVoltageSource(Node *n1, Node *n2, Node *n3, Node *n4, Branch *b1, double gain, unsigned long newKey) {
		node1 = n1;
		node2 = n2;
		node3 = n3;
		node4 = n4;
		branch1 = b1;
		value = gain;
		key = newKey;
	}

	VoltageControlledVoltageSource::~VoltageControlledVoltageSource(void)
	{
	}

	ComponentType VoltageControlledVoltageSource::getComponentType() {
		return ComponentType::VoltageControlledVoltageSource;
	}

	void VoltageControlledVoltageSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {

		(*equationSystem)[node3->getNodeNumber()][branch1->getBranchNumber()] += 1;	
		(*equationSystem)[node4->getNodeNumber()][branch1->getBranchNumber()] -= 1;
		(*equationSystem)[branch1->getBranchNumber()][node1->getNodeNumber()] -= 1;	
		(*equationSystem)[branch1->getBranchNumber()][node2->getNodeNumber()] += 1;

		(*equationSystem)[branch1->getBranchNumber()][node1->getNodeNumber()] += value;
		(*equationSystem)[branch1->getBranchNumber()][node2->getNodeNumber()] -= value;

	}


}