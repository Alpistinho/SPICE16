#pragma once
#include "component.h"
class OpAmp :
	public Component
{
public:
	OpAmp(void);
	~OpAmp(void);
	OpAmp(Node *, Node *, Node *, Node *);
	ComponentType getComponentType(); //returns which type of component it is
	void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double);
	double getValue();

private:
	Node *node1, *node2, *node3, *node4;
};

