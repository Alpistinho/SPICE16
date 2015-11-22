#pragma once
#include <string>
#include <vector>
#include <complex>
#include "Node.h"
enum class ComponentType {Resistor, Capacitor, Inductor, BJT, CurrentSource, VoltageSource, VoltageControlledVoltageSource, CurrentControlledVoltageSource, VoltageControlledCurrentSource, CurrentControlledCurrentSource, OpAmp, Undefined};

class Component
{
public:

	Component(); //the constructor of this class shouldn't be used, but only the ones from the other classes that inherit from this one
	~Component(void);
	
	double getValue(); //returns the value of the component. If it has more than onde, returns the most usual one
	virtual ComponentType getComponentType(); //returns which type of component it is
	//virtual void setNode(unsigned, Node*);//number of the node, pointer to the node
	virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double);

protected:
	double value;
};

