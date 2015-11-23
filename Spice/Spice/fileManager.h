#pragma once

//will read and write the text files. Will also be the reference implementation of using the other classes.
class fileManager
{
public:
	fileManager(void);
	~fileManager(void);

	bool readNetlist();
	bool writeResults();
};

