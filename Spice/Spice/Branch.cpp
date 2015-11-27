#include "stdafx.h"
#include "Branch.h"

namespace spiceSimulator {

	Branch::Branch(void)
	{
	}


	Branch::~Branch(void)
	{
	}

	Branch::Branch(unsigned long branchIdentifier) {
		identifier = branchIdentifier;
	}

	unsigned long Branch::getBranchNumber() {
		return branchNumber;
	}

	void Branch::setBranchNumber(unsigned long position) {
		branchNumber = position;
	}

}