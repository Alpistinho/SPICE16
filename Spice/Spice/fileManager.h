#pragma once
class fileManager
{
public:
	fileManager(void);
	~fileManager(void);

	bool readNetlist();
	bool writeResults();
};

