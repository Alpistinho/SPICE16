#include "stdafx.h"
#include "NodeStorage.h"


NodeStorage::NodeStorage(void)
{
}


NodeStorage::~NodeStorage(void)
{
}

unsigned long NodeStorage::getNodeAmount() {
	return nodeMap.size();
}

Node* NodeStorage::addNode(std::string identifier) {
	
	std::map<std::string, Node*>::iterator it;

	it = nodeMap.find(identifier);
	if (it != nodeMap.end()) { //found the node
		return it->second; //return existing Node
	} else {
		Node* newNode = new Node(identifier);
		return newNode;
	}
}

void NodeStorage::allocateNodeNumbers() {

	unsigned long matrixPosition = 0;

	std::map<std::string, Node*>::iterator it;

	for(it = nodeMap.begin(); it != nodeMap.end(); it++) {
		it->second->setNodeNumber(matrixPosition);
		matrixPosition++;
	}
	return;
}