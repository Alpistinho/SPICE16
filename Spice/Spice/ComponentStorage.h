#pragma once
#include <string>
#include <map>
#include "storage.h"
#include "Component.h"
#include "Node.h"
#include "Branch.h"
#include "CircuitElementStorage.h"

class ComponentStorage :
	public Storage
{
public:

	ComponentStorage(void);
	~ComponentStorage(void);

	//adds a resistor to the model. Returns the generated identifier.
	unsigned addResistor(std::string, std::string, double);



	void removeComponent(unsigned); //removes a component indicated by the passed identifier
	Component getComponent(unsigned); //returns the component indicated by the passed identifier

private:

	unsigned long componentIdentifier; //limits the component number to 4294967295. Hardly a problem
	unsigned long elementsAmount;
	unsigned long branchesNeededAmount; //how many branches will have its current calculated.
	
	//NodeStorage nodeStorage;
	CircuitElementStorage<Node> nodeStorage;
	CircuitElementStorage<Branch> branchStorage;
	std::map<unsigned long, Component> componentMap;
};