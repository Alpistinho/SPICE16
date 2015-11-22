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

	Resistor *resistor;

	resistor = new Resistor(node1, node2, value);

	componentMap[++componentIdentifier] = resistor;
	componentIdentifier++;

	return componentIdentifier;//identifies the component added

}

void ComponentStorage::getFrequencySystem(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {
	unsigned long systemSize = nodeStorage.getNodeAmount() + branchStorage.getBranchAmount();
	
	*equationSystem = std::vector<std::vector<std::complex<double>>>(); //clear the matrix
	equationSystem->resize(systemSize + 1); 
	for(unsigned long i = 0; i < systemSize; i++ ) {
		(*equationSystem)[i].resize(systemSize + 2);
	} //resized the matrix

	std::map<unsigned long, Component*>::iterator it;
	Component *dummyComponent;
	for(it = componentMap.begin(); it != componentMap.end(); it++) {
		dummyComponent = it->second;
		dummyComponent->getFrequencyStamp(equationSystem, frequency);
	}

}

unsigned long ComponentStorage::getSystemSize(){
	return nodeStorage.getNodeAmount() + branchStorage.getBranchAmount();
}

void ComponentStorage::allocateNodeNumbers() {
	nodeStorage.allocateNodeNumbers();
}