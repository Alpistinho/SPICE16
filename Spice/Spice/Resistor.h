#pragma once
#include <string>
#include "component.h"
#include "Node.h"

namespace spiceSimulator {

	class Resistor :
		public Component
	{
	public:
		Resistor(void);

		//constructs resistor with two nodes and its value
		Resistor(Node *, Node *, double, unsigned long);
		~Resistor(void);

		void setValue(double);
		double getValue();
		ComponentType getComponentType(); 
		void getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double);

	private:
		Node* node1;
		Node* node2;
	};

}