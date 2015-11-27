#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <complex>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>

#include "ComponentStorage.h"

namespace spiceSimulator {

	//will read and write the text files. Will also be the reference implementation of using the other classes.
	class FileManager
	{
	public:
		FileManager(void);
		~FileManager(void);

		void readNetlist(std::string, ComponentStorage*, FrequencySimulation *);
		void writeResults(std::map<double,std::vector<std::complex<double>>*>*);

	private:


	};

}