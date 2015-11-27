#pragma once
#include <vector>
#include <complex>
#include <map>
#include "ComponentStorage.h"

namespace spiceSimulator {

	class Simulation
	{
	public:
		Simulation(void);
		~Simulation(void);

		void setTolerance();
		void getTolerance();


	protected:
		double tolerance;

	
	

	};

}