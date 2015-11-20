#pragma once
#include <string>
#include "circuitelement.h"
class Node :
	public CircuitElement
{
public:
	Node(void);
	Node(std::string);
	~Node(void);
};

