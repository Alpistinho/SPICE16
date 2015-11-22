#pragma once
#include <string>
#include "circuitelement.h"
class Node :
	public CircuitElement
{
public:
	friend class NodeStorage;
	Node(void);
	Node(std::string);
	~Node(void);
	unsigned long getNodeNumber();
	

private:
	std::string identifier;
	unsigned long nodeNumber; //holds the position this nodes is on the equation matrix
	void setNodeNumber(unsigned long);
};

