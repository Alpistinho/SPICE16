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

private:
	unsigned long equations;
	double tolerance;

	//holds the matrix that will be solved
	std::vector<std::vector<std::complex<double>>> equationSystem;
	
	//holds the solutions. The key is the frequency/time.
	template<class simulationVariable>
	std::map<double, std::vector<simulationVariable>> results;

	//solves the system and returns the result
	template<class simulationVariable>
	std::vector<simulationVariable> solveEquationSystem();


};

