#include "stdafx.h"
#include "BranchStorage.h"


BranchStorage::BranchStorage(void)
{
}


BranchStorage::~BranchStorage(void)
{
}

unsigned long BranchStorage::getBranchAmount() {
	return branchMap.size();
}

Branch* BranchStorage::addBranch(std::string identifier) {
	
	std::map<std::string, Branch*>::iterator it;

	it = branchMap.find(identifier);
	if (it != branchMap.end()) { //found the node
		return it->second; //return existing Node
	} else {
		Branch* newBranch = new Branch(identifier);
		return newBranch;
	}
}

void BranchStorage::allocateBranchNumbers() {

	unsigned long matrixPosition = 0;

	std::map<std::string, Branch*>::iterator it;

	for(it = branchMap.begin(); it != branchMap.end(); it++) {
		it->second->setBranchNumber(matrixPosition);
		matrixPosition++;
	}
	return;
}