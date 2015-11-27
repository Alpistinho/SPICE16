#include "stdafx.h"
#include "Component.h"

namespace spiceSimulator {

	Component::Component(void)
	{
	}


	Component::~Component(void)
	{
	}

	ComponentType Component::getComponentType() {
		return ComponentType::Undefined;
	}

	double Component::getValue() {
		return value;
	}

	void Component::getFrequencyStamp(std::vector<std::vector<std::complex<double>>>*, double) {
		return; //there is no stamp for the generic component
	}

	unsigned long Component::getKey() {
		return key;
	}

}