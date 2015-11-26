#include "stdafx.h"
#include "ComponentStorage.h"



ComponentStorage::ComponentStorage(void)
{
	componentIdentifier = 0;
}


ComponentStorage::~ComponentStorage(void)
{
}

unsigned ComponentStorage::addResistor(std::string n1, std::string n2, double value) {
	
	++componentIdentifier;

	Node* node1 = nodeStorage.addNode(n1);
	Node* node2 = nodeStorage.addNode(n2);
	
	Resistor *resistor = new Resistor(node1, node2, value, componentIdentifier);
	node1->addComponent(resistor);
	node2->addComponent(resistor);

	componentMap[componentIdentifier] = resistor;

	return componentIdentifier;//identifies the component added

}

unsigned ComponentStorage::addCapacitor(std::string n1, std::string n2, double value) {
	
	++componentIdentifier;

	Node* node1 = nodeStorage.addNode(n1);
	Node* node2 = nodeStorage.addNode(n2);

	Capacitor *capacitor = new Capacitor(node1, node2, value, componentIdentifier);

	node1->addComponent(capacitor);
	node2->addComponent(capacitor);

	componentMap[componentIdentifier] = capacitor;

	return componentIdentifier;//identifies the component added

}

unsigned ComponentStorage::addInductor(std::string n1, std::string n2, double value) {
	
	++componentIdentifier;

	Node* node1 = nodeStorage.addNode(n1);
	Node* node2 = nodeStorage.addNode(n2);
	Branch* branch1 = branchStorage.addBranch(componentIdentifier);
	
	Inductor *inductor = new Inductor(node1, node2, branch1, value, componentIdentifier);
	
	node1->addComponent(inductor);
	node2->addComponent(inductor);

	componentMap[componentIdentifier] = inductor;

	return componentIdentifier;//identifies the component added

}

unsigned ComponentStorage::addCurrentControlledCurrentSource(std::string n1, std::string n2, std::string n3, std::string n4, double value) {
	
	++componentIdentifier;

	Node* node1 = nodeStorage.addNode(n1);
	Node* node2 = nodeStorage.addNode(n2);
	Node* node3 = nodeStorage.addNode(n3);
	Node* node4 = nodeStorage.addNode(n4);
	Branch* branch1 = branchStorage.addBranch(componentIdentifier);

	CurrentControlledCurrentSource *cccs = new CurrentControlledCurrentSource(node1, node2, node3, node4, branch1, value, componentIdentifier);

	node1->addComponent(cccs);
	node2->addComponent(cccs);
	node3->addComponent(cccs);
	node4->addComponent(cccs);

	componentMap[componentIdentifier] = cccs;

	return componentIdentifier;//identifies the component added

}

unsigned ComponentStorage::addCurrentControlledVoltageSource(std::string n1, std::string n2, std::string n3, std::string n4, double value) {
	
	++componentIdentifier;

	Node* node1 = nodeStorage.addNode(n1);
	Node* node2 = nodeStorage.addNode(n2);
	Node* node3 = nodeStorage.addNode(n3);
	Node* node4 = nodeStorage.addNode(n4);
	Branch* branch1 = branchStorage.addBranch(componentIdentifier);

	CurrentControlledVoltageSource *ccvs = new CurrentControlledVoltageSource(node1, node2, node3, node4, branch1, value, componentIdentifier); 

	node1->addComponent(ccvs);
	node2->addComponent(ccvs);
	node3->addComponent(ccvs);
	node4->addComponent(ccvs);

	componentMap[componentIdentifier] = ccvs;

	return componentIdentifier;//identifies the component added

}

unsigned ComponentStorage::addVoltageControlledCurrentSource(std::string n1, std::string n2, std::string n3, std::string n4, double value) {
	
	++componentIdentifier;

	Node* node1 = nodeStorage.addNode(n1);
	Node* node2 = nodeStorage.addNode(n2);
	Node* node3 = nodeStorage.addNode(n3);
	Node* node4 = nodeStorage.addNode(n4);

	VoltageControlledCurrentSource *vccs = new VoltageControlledCurrentSource(node1, node2, node3, node4, value, componentIdentifier); 

	node1->addComponent(vccs);
	node2->addComponent(vccs);
	node3->addComponent(vccs);
	node4->addComponent(vccs);

	componentMap[componentIdentifier] = vccs;

	return componentIdentifier;//identifies the component added

}

unsigned ComponentStorage::addVoltageControlledVoltageSource(std::string n1, std::string n2, std::string n3, std::string n4, double value) {
	
	++componentIdentifier;

	Node* node1 = nodeStorage.addNode(n1);
	Node* node2 = nodeStorage.addNode(n2);
	Node* node3 = nodeStorage.addNode(n3);
	Node* node4 = nodeStorage.addNode(n4);
	Branch* branch1 = branchStorage.addBranch(componentIdentifier);

	VoltageControlledVoltageSource *vcvs = new VoltageControlledVoltageSource(node1, node2, node3, node4, branch1, value, componentIdentifier); 

	node1->addComponent(vcvs);
	node2->addComponent(vcvs);
	node3->addComponent(vcvs);
	node4->addComponent(vcvs);

	componentMap[componentIdentifier] = vcvs;

	return componentIdentifier;//identifies the component added

}

unsigned ComponentStorage::addBJT(std::string n1, std::string n2, std::string n3, double HFE, double HIE, double HRE, double HOE, double CBE, double CBC) {
	
	++componentIdentifier;

	Node* node1 = nodeStorage.addNode(n1);
	Node* node2 = nodeStorage.addNode(n2);
	Node* node3 = nodeStorage.addNode(n3);

	BJT *bjt = new BJT(node1, node2, node3, HFE, HIE, HRE, HOE, CBE, CBC , componentIdentifier); 

	node1->addComponent(bjt);
	node2->addComponent(bjt);
	node3->addComponent(bjt);

	componentMap[componentIdentifier] = bjt;

	return componentIdentifier;//identifies the component added

}

unsigned ComponentStorage::addVoltageSource(std::string n1, std::string n2, double voltage, double phase) {
	
	++componentIdentifier;

	Node* node1 = nodeStorage.addNode(n1);
	Node* node2 = nodeStorage.addNode(n2);
	Branch* branch1 = branchStorage.addBranch(componentIdentifier);
	
	VoltageSource *voltageSource = new VoltageSource(node1, node2, branch1, voltage, phase, componentIdentifier);
	
	node1->addComponent(voltageSource);
	node2->addComponent(voltageSource);

	componentMap[componentIdentifier] = voltageSource;

	return componentIdentifier;//identifies the component added

}

unsigned ComponentStorage::addCurrentSource(std::string n1, std::string n2, double current, double phase) {
	
	++componentIdentifier;

	Node* node1 = nodeStorage.addNode(n1);
	Node* node2 = nodeStorage.addNode(n2);
	
	CurrentSource *currentSource = new CurrentSource(node1, node2, current, phase, componentIdentifier);
	
	node1->addComponent(currentSource);
	node2->addComponent(currentSource);

	componentMap[componentIdentifier] = currentSource;

	return componentIdentifier;//identifies the component added

}

unsigned ComponentStorage::addOpAmp(std::string n1, std::string n2, std::string n3, std::string n4) {
	
	++componentIdentifier;

	Node* node1 = nodeStorage.addNode(n1);
	Node* node2 = nodeStorage.addNode(n2);
	Node* node3 = nodeStorage.addNode(n3);
	Node* node4 = nodeStorage.addNode(n4);
	Branch* branch1 = branchStorage.addBranch(componentIdentifier);

	OpAmp *opAmp = new OpAmp(node1, node2, node3, node4, branch1, componentIdentifier); 

	node1->addComponent(opAmp);
	node2->addComponent(opAmp);
	node3->addComponent(opAmp);
	node4->addComponent(opAmp);

	componentMap[componentIdentifier] = opAmp;

	return componentIdentifier;//identifies the component added

}

void ComponentStorage::getFrequencySystem(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {
	unsigned long systemSize = getSystemSize();
	
	*equationSystem = std::vector<std::vector<std::complex<double>>>(); //clear the matrix
	equationSystem->resize(systemSize); 
	for(unsigned long i = 0; i < systemSize; i++ ) {
		(*equationSystem)[i].resize(systemSize + 1);
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
	unsigned long matrixPosition;
	matrixPosition = nodeStorage.allocateNodeNumbers();
	branchStorage.allocateBranchNumbers(matrixPosition);
}