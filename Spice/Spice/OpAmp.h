#pragma once
#include "component.h"
#include "Node.h"
#include "Branch.h"

namespace spiceSimulator {

	class OpAmp :
		public Component
	{
	public:
		OpAmp(void);
		~OpAmp(void);
		OpAmp(Node *, Node *, Node *, Node *, Branch *, unsigned long);
		ComponentType getComponentType(); //returns which type of component it is
		void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double);
		double getValue();

	private:
		Node *node1, *node2, *node3, *node4;
		Branch *branch1;
	};

}