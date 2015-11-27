#include "stdafx.h"
#include "BJT.h"


BJT::BJT(void)
{
}


BJT::BJT(Node *n1, Node *n2, Node *n3, double HFE, double HIE, double HRE, double HOE, double CBE, double CBC, unsigned long newKey) {
	node1 = n1;
	node2 = n2;
	node3 = n3;
	hfe = HFE;
	hie = HIE;
	hre = HRE;
	hoe = HOE;
	cbe = CBE;
	cbc = CBC;
	key = newKey;
}

BJT::~BJT(void)
{
}

ComponentType BJT::getComponentType() {
	return ComponentType::BJT;
}

void BJT::getFrequencyStamp(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {
	
	(*equationSystem)[node1->getNodeNumber()][node1->getNodeNumber()] += hoe - (hfe*hre)/hie;
	(*equationSystem)[node1->getNodeNumber()][node2->getNodeNumber()] += hfe/hie;
	(*equationSystem)[node1->getNodeNumber()][node3->getNodeNumber()] -= hoe + ( ((1-hre)*hfe)/hie );

	(*equationSystem)[node2->getNodeNumber()][node1->getNodeNumber()] -=  (hre/hie);
	(*equationSystem)[node2->getNodeNumber()][node2->getNodeNumber()] +=  (1/hie);
	(*equationSystem)[node2->getNodeNumber()][node3->getNodeNumber()] +=  (hre - 1)/hie;

	(*equationSystem)[node3->getNodeNumber()][node1->getNodeNumber()] += -hoe + (1/hie) * ( (1 + hfe) * hre);
	(*equationSystem)[node3->getNodeNumber()][node2->getNodeNumber()] -= (1/hie) * (1 + hfe);
	(*equationSystem)[node3->getNodeNumber()][node3->getNodeNumber()] += hoe + (1/hie) * (1 + hfe) * (1 - hre);

	//parasitic capacitors
	
	(*equationSystem)[node1->getNodeNumber()][node1->getNodeNumber()] += std::complex<double>(0,frequency*cbc);
	(*equationSystem)[node1->getNodeNumber()][node2->getNodeNumber()] -= std::complex<double>(0,frequency*cbc);
	(*equationSystem)[node2->getNodeNumber()][node1->getNodeNumber()] -= std::complex<double>(0,frequency*cbc);
	(*equationSystem)[node2->getNodeNumber()][node2->getNodeNumber()] += std::complex<double>(0,frequency*cbc);

	(*equationSystem)[node1->getNodeNumber()][node1->getNodeNumber()] += std::complex<double>(0,frequency*cbe);
	(*equationSystem)[node1->getNodeNumber()][node3->getNodeNumber()] -= std::complex<double>(0,frequency*cbc);
	(*equationSystem)[node3->getNodeNumber()][node1->getNodeNumber()] -= std::complex<double>(0,frequency*cbc);
	(*equationSystem)[node3->getNodeNumber()][node3->getNodeNumber()] += std::complex<double>(0,frequency*cbc);

}