#include "stdafx.h"
#include "CurrentSource.h"


CurrentSource::CurrentSource(void)
{
}

CurrentSource::CurrentSource(Node* n1, Node* n2, double current) {
	node1 = n1;
	node2 = n2;
	value = current;
}

CurrentSource::~CurrentSource(void)
{
}

ComponentType CurrentSource::getComponentType() {
	return ComponentType::CurrentSource;
}
