#pragma once
#include "Component.h"
class VoltageSource :
	public Component
{
public:
	VoltageSource(void);
	~VoltageSource(void);
	VoltageSource(Node *, Node*, double);
	void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double);
};

