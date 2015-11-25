#pragma once
#include <string>
#include <map>
#include "storage.h"
#include "Branch.h"
class BranchStorage : public Storage {

public:

	BranchStorage(void);

	//adds a new node with the identifier especified. Returns a pointer to the new node if it doesn`t exists or a pointer to the old node if it already exists
	Branch* addBranch(unsigned long);
	~BranchStorage(void);

	Branch* getBranch(unsigned long);//get a branch by its "position". Calling that from 0 to end will give return all the elements 
	Branch* getBranch(std::string); //get a branch by its identifier

	void removeBranch(unsigned long); //remove a branch by the identifier of its component

	void allocateBranchNumbers(unsigned long); //gives each branch its position on the matrix
	unsigned long getBranchAmount();

private:
	
	std::map<unsigned long, Branch*> branchMap; //its mapped by the component identifier
};


