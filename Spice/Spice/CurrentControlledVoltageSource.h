#pragma once
#include "component.h"
#include "Node.h"
#include "Branch.h"

class CurrentControlledVoltageSource :
	public Component
{
public:
	CurrentControlledVoltageSource(void);
	~CurrentControlledVoltageSource(void);
	CurrentControlledVoltageSource(Node *, Node *,  Node *, Node *, Branch *, double, unsigned long);
	ComponentType getComponentType(); //returns which type of component it is
	void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double);
	double getValue();

private:

	Node *node1, *node2, *node3, *node4;
	Branch *branch1, *branch2;
};

