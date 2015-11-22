#include "stdafx.h"
#include "CurrentControlledVoltageSource.h"


CurrentControlledVoltageSource::CurrentControlledVoltageSource(void)
{
}

CurrentControlledVoltageSource::CurrentControlledVoltageSource(Node *n1, Node *n2, Node *n3, Node *n4, double gain) {
	node1 = n1;
	node2 = n2;
	node3 = n3;
	node4 = n4;
	value = gain;
}

CurrentControlledVoltageSource::~CurrentControlledVoltageSource(void)
{
}

ComponentType CurrentControlledVoltageSource::getComponentType() {
	return ComponentType::CurrentControlledVoltageSource;
}