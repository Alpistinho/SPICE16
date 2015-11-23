#pragma once
#include <complex>
#include "component.h"

class CurrentSource :
	public Component
{
public:
	CurrentSource(void);
	CurrentSource(Node*, Node*, double, double);
	~CurrentSource(void);
	ComponentType getComponentType(); //returns which type of component it is
	void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double);
	double getValue();

private:
	Node *node1, *node2;
	std::complex<double> value; //the independent sources have modulus and phase components in its value. It is stored as a phasor
};


