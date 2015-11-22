#pragma once
#include "component.h"
#include "Node.h"
#include "Branch.h"
class Inductor :
	public Component
{
public:
	Inductor(void);
	~Inductor(void);
	Inductor(Node *, Node *, Branch *, double);
	ComponentType getComponentType(); //returns which type of component it is
	void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double);
	double getValue();

private:

	Node *node1, *node2;
	Branch *branch1;
};

