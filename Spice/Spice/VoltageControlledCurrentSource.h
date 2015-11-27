#pragma once
#include "component.h"
#include "Node.h"

namespace spiceSimulator {

	class VoltageControlledCurrentSource :
		public Component
	{
	public:
		VoltageControlledCurrentSource(void);
		~VoltageControlledCurrentSource(void);
		VoltageControlledCurrentSource(Node *, Node *,  Node *, Node *, double, unsigned long);
		ComponentType getComponentType(); //returns which type of component it is
		void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double);
		double getValue();

	private:

		Node *node1, *node2, *node3, *node4;
	};

}