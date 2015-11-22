#include "stdafx.h"
#include "Inductor.h"


Inductor::Inductor(void)
{
}

Inductor::Inductor(Node *n1, Node *n2, Branch *b1, double inductance) {

	node1 = n1;
	node2 = n2;
	branch1 = b1;

}

Inductor::~Inductor(void)
{
}

ComponentType Inductor::getComponentType() {
	return ComponentType::Inductor;
}