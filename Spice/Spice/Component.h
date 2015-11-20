#pragma once
#include <string>
#include <vector>
#include "Node.h"
enum class ComponentType {Resistor, Capacitor, Inductor};

class Component
{
public:

	Component(); //the constructor of this class shouldn't be used, but only the ones from the other classes that inherit from this one
	~Component(void);
	
	virtual std::vector<double> getParameters(); //returns a vector with all numeric parameters the component have
	virtual unsigned getParameterAmount(); //return how many parameter a certain component have
	virtual ComponentType getComponentType(); //returns which type of component it is
	virtual void setNode(unsigned, Node*);//number of the node, pointer to the node
	virtual std::vector<std::vector<double>> getFrequencyStamp(double);
	virtual 
};

