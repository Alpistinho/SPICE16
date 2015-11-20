#include "stdafx.h"
#include "ComponentStorage.h"
#include "Resistor.h"


ComponentStorage::ComponentStorage(void)
{
}


ComponentStorage::~ComponentStorage(void)
{
}

unsigned ComponentStorage::addResistor(std::string n1, std::string n2, double value) {
	
	Node* node1 = nodeStorage.addNode(n1);
	Node* node2 = nodeStorage.addNode(n2);

	Resistor resistor(node1, node2, value);

	componentMap[++componentIdentifier] = resistor;

	return componentIdentifier;//identifies the component added


}