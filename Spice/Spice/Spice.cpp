// Spice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "ComponentStorage.h"
#include "fileManager.h"
#include "FrequencySimulation.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ComponentStorage componentStorage;
	FrequencySimulation freqSim;
	FileManager fileManager;
	cout <<'1' <<endl;
	fileManager.readNetlist("teste.net",&componentStorage,&freqSim);
	cout << '2' <<endl;
	cout << componentStorage.getSystemSize();
	fileManager.writeResults(freqSim.simulateFrequencyResponse(&componentStorage));

	

	return 0;
}

