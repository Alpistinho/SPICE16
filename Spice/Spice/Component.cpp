#include "stdafx.h"
#include "Component.h"


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
