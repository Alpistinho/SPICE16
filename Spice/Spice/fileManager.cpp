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
	cout <<'3' << endl;
    while (getline(file, str)) {
		cout << '4' << endl;
		line.clear();
		cout <<'5' <<endl;
        stringstream ss(str);
		cout <<'6' <<endl;
		string item;
		cout <<'7' <<endl;
		while (getline(ss, item, ' ')) {
			line.push_back(item);
		}
		cout <<'8' << endl;
		cout << str << endl;
		switch (line[0][0]) {//switch on the first char of the first string. No error treatment

		case 'R':
			cout <<'r' <<endl;
			componentStorage->addResistor(line[1], line[2], stod(line[3]));
			break;

		case 'C':
			cout <<'c' <<endl;
			componentStorage->addCapacitor(line[1], line[2], stod(line[3]));
			break;

		case 'L':
			componentStorage->addInductor(line[1], line[2], stod(line[3]));
			break;

		case 'V':
			cout <<'v' <<endl;
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
	cout << '9' <<endl;
	return;
}

void FileManager::writeResults(map<double,vector<complex<double>>*>* results) {
	cout << endl << endl;
	map<double,vector<complex<double>>*>::iterator it;
	ofstream resultFile;
	resultFile.open("Results.txt");
	for(it = results->begin(); it != results->end(); it++) {
		for(unsigned i = 0; i < it->second->size(); i++) {
			complex<double> value = (*(it->second))[i];
			//cout << abs(value) << ' ' << (180/M_PI)*atan2(imag(value), real(value)) << ',';
			resultFile << abs(value) << ',' << (180/M_PI)*atan2(imag(value), real(value)) << ',';
		}
		cout << endl;
		resultFile << endl;
	}

	return;
}