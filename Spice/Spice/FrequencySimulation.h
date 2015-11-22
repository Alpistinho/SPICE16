#pragma once
#include <vector>
#include <map>
#include <complex>
#include <cmath>
#include "simulation.h"
#include "ComponentStorage.h"

class FrequencySimulation :
	public Simulation
{
public:
	FrequencySimulation(void);
	~FrequencySimulation(void);


	std::map<double, std::vector<std::complex<double>>*>* simulateFrequencyResponse(ComponentStorage*, double, double, unsigned);

private:
	
	

	//holds the solutions. The key is the frequency
	std::map<double, std::vector<std::complex<double>>*> *results;

	//solves the system and returns the result
	std::vector<std::complex<double>>* solveEquationSystem(std::vector<std::vector<std::complex<double>>>&);
		
};

