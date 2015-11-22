#pragma once
#include <string>
#include <map>
#include <complex>
#include <vector>
#include "storage.h"
#include "Component.h"
#include "Node.h"
#include "NodeStorage.h"
#include "Branch.h"
#include "BranchStorage.h"

class ComponentStorage :
	public Storage
{
public:
	friend class FrequencySimulation;
	ComponentStorage(void);
	~ComponentStorage(void);

	//adds a resistor to the model. Returns the generated identifier.
	unsigned addResistor(std::string, std::string, double);

	void removeComponent(unsigned); //removes a component indicated by the passed identifier
	Component getComponentByIdentifier(unsigned); //returns the component indicated by the passed identifier
	void getFrequencySystem(std::vector<std::vector<std::complex<double>>>*, double); 
	void allocateNodeNumbers();
	unsigned long getSystemSize();


private:

	unsigned long componentIdentifier; //limits the component amount to 4294967295. Hardly a problem
	unsigned long elementsAmount;
	unsigned long branchesNeededAmount; //how many branches will have its current calculated.
	
	NodeStorage nodeStorage;
	BranchStorage branchStorage;
	std::map<unsigned long, Component*> componentMap;

	
};