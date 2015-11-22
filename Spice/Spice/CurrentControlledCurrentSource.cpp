#include "stdafx.h"
#include "CurrentControlledCurrentSource.h"


CurrentControlledCurrentSource::CurrentControlledCurrentSource(void)
{
}

CurrentControlledCurrentSource::CurrentControlledCurrentSource(Node *n1, Node *n2, Node *n3, Node *n4, double gain) {
	node1 = n1;
	node2 = n2;
	node3 = n3;
	node4 = n4;
	value = gain;
}

CurrentControlledCurrentSource::~CurrentControlledCurrentSource(void)
{
}

ComponentType CurrentControlledCurrentSource::getComponentType() {
	return ComponentType::CurrentControlledCurrentSource;
}
