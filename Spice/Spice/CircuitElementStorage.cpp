#include "stdafx.h"
#include "CircuitElementStorage.h"

template<class circuitElement>
CircuitElementStorage::CircuitElementStorage(void)
{
}

template<class circuitElement>
CircuitElementStorage::~CircuitElementStorage(void)
{
}

template<class circuitElement>
circuitElement* circuitElementStorage::addcircuitElement(std::string identifier) {
	
	std::map<std::string, circuitElement*>::iterator it;

	it = circuitElementMap.find(identifier);
	if (it != circuitElementMap.end()) { //found the node
		return it->second; //return existing Node
	} else {
		circuitElement* newCircuitElement = new circuitElement(identifier);
		return newCircuitElement;
	}
}