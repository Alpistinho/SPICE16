#pragma once
#include <vector>
#include <complex>
#include <map>
#include "ComponentStorage.h"


class Simulation
{
public:
	Simulation(void);
	~Simulation(void);

	unsigned long getRowsAmount();
	unsigned long getColumnsAmount();
	void setTolerance();
	void getTolerance();


protected:
	unsigned long equationsAmount;
	double tolerance;

	
	

};

