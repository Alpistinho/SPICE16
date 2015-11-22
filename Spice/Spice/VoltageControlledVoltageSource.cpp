#include "stdafx.h"
#include "VoltageControlledVoltageSource.h"


VoltageControlledVoltageSource::VoltageControlledVoltageSource(void)
{
}

VoltageControlledVoltageSource::VoltageControlledVoltageSource(Node *n1, Node *n2, Node *n3, Node *n4, double gain) {
	node1 = n1;
	node2 = n2;
	node3 = n3;
	node4 = n4;
	value = gain;
}

VoltageControlledVoltageSource::~VoltageControlledVoltageSource(void)
{
}

ComponentType VoltageControlledVoltageSource::getComponentType() {
	return ComponentType::VoltageControlledVoltageSource;
}
