// Spice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ComponentStorage.h"
#include "fileManager.h"
#include "FrequencySimulation.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ComponentStorage componentStorage;
	FrequencySimulation freqSim;
	FileManager fileManager;
	fileManager.readNetlist("teste.net",&componentStorage,&freqSim);
	fileManager.writeResults(freqSim.simulateFrequencyResponse(&componentStorage));

	

	return 0;
}

