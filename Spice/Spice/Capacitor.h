#pragma once
#include "component.h"
class Capacitor :
	public Component
{
public:
	Capacitor(void);
	~Capacitor(void);
	Capacitor(Node *, Node *, double);

	ComponentType getComponentType();
	void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double);

private:
	Node *node1, *node2;

};

