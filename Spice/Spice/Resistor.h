#pragma once
#include <string>
#include "component.h"
#include "Node.h"
class Resistor :
	public Component
{
public:
	Resistor(void);

	//constructs resistor with two nodes and its value
	Resistor(Node *, Node *, double);
	void setValue(double);
	~Resistor(void);
};

