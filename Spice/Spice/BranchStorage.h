#pragma once
#include <string>
#include <map>
#include "storage.h"
#include "Branch.h"
class BranchStorage : public Storage {

public:

	BranchStorage(void);

	//adds a new node with the identifier especified. Returns a pointer to the new node if it doesn`t exists or a pointer to the old node if it already exists
	Branch* addNode(std::string);
	~BranchStorage(void);

	Branch* getBranch(unsigned long);//get a branch by its "position". Calling that from 0 to end will give return all the elements 
	Branch* getBranch(std::string); //get a branch by its identifier

	void allocateBranchNumbers(); //gives each branch its position on the matrix
	unsigned long getBranchAmount();

private:
	
	std::map<std::string, Branch*> branchMap;
};


