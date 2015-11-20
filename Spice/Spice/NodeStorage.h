#pragma once
#include <map>
#include <string>
#include "storage.h"
#include "Node.h"
class NodeStorage :
	public Storage
{
public:
	NodeStorage(void);

	//adds a new node with the identifier especified. Returns a pointer to the new node if it doesn`t exists or a pointer to the old node if it already exists
	Node* addNode(std::string);
	~NodeStorage(void);

private:
	
	std::map<std::string, Node*> nodeMap;
};

