#pragma once
#include "Component.h"
#include "Node.h"
#include "Branch.h"

namespace spiceSimulator {

	class VoltageControlledVoltageSource :
		public Component
	{
	public:
		VoltageControlledVoltageSource(void);
		~VoltageControlledVoltageSource(void);
		VoltageControlledVoltageSource(Node *, Node *,  Node *, Node *, Branch *b1, double, unsigned long);
		ComponentType getComponentType(); //returns which type of component it is
		void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double);
		double getValue();

	private:

		Node *node1, *node2, *node3, *node4;
		Branch *branch1;
	};

}