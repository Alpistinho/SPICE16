#pragma once
#include "component.h"
#include "Node.h"

class Capacitor :
	public Component
{
public:
	Capacitor(void);
	~Capacitor(void);
	Capacitor(Node *, Node *, double, unsigned long newKey);

	ComponentType getComponentType();
	void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double);

private:
	Node *node1, *node2;

};

