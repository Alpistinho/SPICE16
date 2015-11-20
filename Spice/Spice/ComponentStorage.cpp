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
	
	Node* node1 = nodeStorage.addCircuitElement(n1);
	Node* node2 = nodeStorage.addCircuitElement(n2);

	Resistor resistor(node1, node2, value);

	componentMap[++componentIdentifier] = resistor;
	componentIdentifier++;

	return componentIdentifier;//identifies the component added


}