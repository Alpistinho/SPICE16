#include "stdafx.h"
#include "BJT.h"


BJT::BJT(void)
{
}


BJT::BJT(Node *n1, Node *n2, Node *n3, double HFE, double HIE, double HRE, double HOE, double CBE, double CBC) {
	node1 = n1;
	node2 = n2;
	node3 = n3;
	hfe = HFE;
	hie = HIE;
	hre = HRE;
	hoe = HOE;
	cbe = CBE;
	cbc = CBC;
}

BJT::~BJT(void)
{
}

ComponentType BJT::getComponentType() {
	return ComponentType::BJT;
}