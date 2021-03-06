#pragma once
#include "component.h"
#include "Node.h"
#include "Branch.h"

namespace spiceSimulator {

	class CurrentControlledCurrentSource :
		public Component
	{
	public:
		CurrentControlledCurrentSource(void);
		~CurrentControlledCurrentSource(void);
		CurrentControlledCurrentSource(Node *, Node *,  Node *, Node *, Branch*, double, unsigned long);
		ComponentType getComponentType(); //returns which type of component it is
		void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double);

	private:

		Node *node1, *node2, *node3, *node4;
		Branch *branch1;
	};

}