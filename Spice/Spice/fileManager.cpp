#include "stdafx.h"
#include "FileManager.h"
#include "FrequencySimulation.h"

using namespace std;

FileManager::FileManager(void)
{
}


FileManager::~FileManager(void)
{
}

void FileManager::readNetlist(string fileName, ComponentStorage *componentStorage, FrequencySimulation *freqSim) {
	
	std::ifstream file(fileName);
    std::string str; 
	vector<string> line;
    while (getline(file, str)) {
		line.clear();
        stringstream ss(str);
		string item;
		while (getline(ss, item, ' ')) {
			line.push_back(item);
		}
		switch (line[0][0]) {//switch on the first char of the first string. No error treatment

		case 'R':
			componentStorage->addResistor(line[1], line[2], stod(line[3]));
			break;

		case 'C':
			componentStorage->addCapacitor(line[1], line[2], stod(line[3]));
			break;

		case 'L':
			componentStorage->addInductor(line[1], line[2], stod(line[3]));
			break;

		case 'V':
			componentStorage->addVoltageSource(line[1], line[2], stod(line[3]), stod(line[4]));
			break;

		case 'I':
			componentStorage->addCurrentSource(line[1], line[2], stod(line[3]), stod(line[4]));
			break;

		case 'E':
			componentStorage->addVoltageControlledVoltageSource(line[1], line[2], line[3], line[4], stod(line[5]));
			break;

		case 'F':
			componentStorage->addCurrentControlledCurrentSource(line[1], line[2], line[3], line[4], stod(line[5]));
			break;

		case 'G':
			componentStorage->addVoltageControlledCurrentSource(line[1], line[2], line[3], line[4], stod(line[5]));
		break;

		case 'H':
			componentStorage->addCurrentControlledVoltageSource(line[1], line[2], line[3], line[4], stod(line[5]));
			break;

		case 'O':
			componentStorage->addOpAmp(line[1], line[2], line[3], line[4]);
			break;

		case '.': //condiguration line
			freqSim->setParameters(stod(line[2]), stod(line[3]), stod(line[1]));
			//format is .AC      points   initial  final
			//         line[0]   line[1]  line[2]  line[3]
			break;
		default:
			break;
		}

    }

	return;
}

void FileManager::writeResults(map<double,vector<complex<double>>*>* results) {

	map<double,vector<complex<double>>*>::iterator it;
	ofstream resultFile;
	resultFile.open("Results.txt");

	for(it = results->begin(); it != results->end(); it++) {
		for(unsigned i = 0; i < it->second->size(); i++) {

			complex<double> value = (*(it->second))[i];
			double frequency = it->first;
			resultFile << frequency << "," << abs(value) << ',' << (180/M_PI)*atan2(imag(value), real(value)) << ',';

		}
		resultFile << endl;
	}

	return;
}