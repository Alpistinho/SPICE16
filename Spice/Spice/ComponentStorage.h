#pragma once
#include <string>
#include <map>
#include "storage.h"
#include "Component.h"
#include "NodeStorage.h"

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
	NodeStorage nodeStorage;
	std::map<unsigned long, Component> componentMap;
};