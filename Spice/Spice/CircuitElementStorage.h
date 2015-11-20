#pragma once
#include <string>
#include <map>

template<class circuitElement>

class CircuitElementStorage
{
public:
	CircuitElementStorage(void);
	~CircuitElementStorage(void);

	//adds a new circuit element with the identifier especified. Returns a pointer to the new element if it doesn`t exists or a pointer to the old node if it already exists
	circuitElement* addCircuitElement(std::string);

private:
	
	std::map<std::string, circuitElement*> circuitElement;
};

