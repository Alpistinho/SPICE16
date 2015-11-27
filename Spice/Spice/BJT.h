#pragma once
#include "component.h"
#include "Node.h"
namespace spiceSimulator {

	class BJT :
		public Component
	{
	public:
		BJT(void);
		~BJT(void);
		BJT(Node *, Node *, Node *, double, double, double, double, double, double, unsigned long);
		ComponentType getComponentType();
		void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>* , double);

	private:
		Node *node1, *node2, *node3;
		double hfe, hie, hre, hoe, cbe, cbc;
	};

}