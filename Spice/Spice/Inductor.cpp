#include "stdafx.h"
#include "Inductor.h"

namespace spiceSimulator {

	Inductor::Inductor(void)
	{
	}

	Inductor::Inductor(Node *n1, Node *n2, Branch *b1, double inductance, unsigned long newKey) {

		node1 = n1;
		node2 = n2;
		branch1 = b1;
		key = newKey;
		value = inductance;
	}

	Inductor::~Inductor(void)
	{
	}

	ComponentType Inductor::getComponentType() {
		return ComponentType::Inductor;
	}

	void Inductor::getFrequencyStamp(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {

		(*equationSystem)[branch1->getBranchNumber()][node1->getNodeNumber()] -= 1;
		(*equationSystem)[branch1->getBranchNumber()][node2->getNodeNumber()] += 1;
		(*equationSystem)[node1->getNodeNumber()][branch1->getBranchNumber()] += 1;
		(*equationSystem)[node2->getNodeNumber()][branch1->getBranchNumber()] -= 1;
		(*equationSystem)[branch1->getBranchNumber()][branch1->getBranchNumber()] += std::complex<double>(0,	frequency*value);


	}

}