#pragma once
#include <vector>
#include <map>
#include "simulation.h"
#include "ComponentStorage.h"

class FrequencySimulation :
	public Simulation
{
public:
	FrequencySimulation(void);
	~FrequencySimulation(void);

	//create the equation system
	void mountSystem(ComponentStorage);

	std::map<double, std::vector<std::complex<double>>>* simulateFrequencyResponse(double, double, unsigned);

private:
	
	std::map<double, std::vector<std::complex<double>>> results;

	std::vector<std::complex<double>> solveEquationSystem();
};

