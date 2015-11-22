#pragma once
#include "component.h"
class BJT :
	public Component
{
public:
	BJT(void);
	~BJT(void);
	BJT(Node *, Node *, Node *, double, double, double, double, double, double);
	ComponentType getComponentType();

private:
	Node *node1, *node2, *node3;
	double hfe, hie, hre, hoe, cbe, cbc;
};

