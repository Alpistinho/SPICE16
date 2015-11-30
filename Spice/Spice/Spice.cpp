// Spice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ComponentStorage.h"
#include "fileManager.h"
#include "FrequencySimulation.h"


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	spiceSimulator::ComponentStorage componentStorage;
	spiceSimulator::FrequencySimulation freqSim;
	spiceSimulator::FileManager fileManager;
	fileManager.readNetlist("test.net",&componentStorage,&freqSim);
	fileManager.writeResults(freqSim.simulateFrequencyResponse(&componentStorage));

	

	return 0;
}

