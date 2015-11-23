#include "stdafx.h"
#include "Node.h"


Node::Node(void)
{
}

Node::Node(std::string nodeIdentifier) {
	identifier = nodeIdentifier;
}

Node::~Node(void)
{
}

unsigned long Node::getNodeNumber() {
	return nodeNumber;
}

void Node::setNodeNumber(unsigned long position) {
	nodeNumber = position;
}

void Node::addComponent(Component *component) {
	componentMap[component->getKey()] = component;
}