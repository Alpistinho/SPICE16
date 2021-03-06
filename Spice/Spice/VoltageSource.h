#pragma once
#include <complex>
#include "Component.h"
#include "Node.h"
#include "Branch.h"

namespace spiceSimulator {

	class VoltageSource :
		public Component
	{
	public:
		VoltageSource(void);
		~VoltageSource(void);
		VoltageSource(Node *, Node*, Branch *, double, double, unsigned long);
		void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double);

	private:
		Node *node1, *node2;
		Branch *branch1;
		std::complex<double> value; //the independent sources have modulus and phase components in its value. It is stored as a phasor

	};

}