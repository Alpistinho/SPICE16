#pragma once
#include <string>
#include "circuitelement.h"
class Branch :
	public CircuitElement
{
public:
	friend class BranchStorage;
	Branch(void);
	Branch(std::string);
	~Branch(void);
	unsigned long getBranchNumber();
	void setBranchNumber(unsigned long);

private:
	std::string identifier;
	unsigned long branchNumber; //holds the position this Branch is on the equation matrix
};