#include "stdafx.h"
#include "NodeStorage.h"


NodeStorage::NodeStorage(void)
{
}


NodeStorage::~NodeStorage(void)
{
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