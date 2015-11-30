#pragma once
#include <string>
#include <map>
#include "circuitelement.h"
#include "component.h"

namespace spiceSimulator {

	class Node :
		public CircuitElement
	{
	public:

		friend class NodeStorage;

		Node(void);
		Node(std::string);
		~Node(void);
		unsigned long getNodeNumber();

		void addComponent(Component*);
	

	private:
		std::string identifier;
		unsigned long nodeNumber; //holds the position this nodes is on the equation matrix
		void setNodeNumber(unsigned long);
		std::map<unsigned long, Component*> componentMap; //stores all the components this node has linked to it.
	};

}