#include "stdafx.h"
#include "Branch.h"


Branch::Branch(void)
{
}


Branch::~Branch(void)
{
}

Branch::Branch(std::string nodeIdentifier) {
	identifier = nodeIdentifier;
}

unsigned long Branch::getBranchNumber() {
	return branchNumber;
}

void Branch::setBranchNumber(unsigned long position) {
	branchNumber = position;
}