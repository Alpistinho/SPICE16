#include "stdafx.h"
#include "FrequencySimulation.h"
#include <iostream>

using namespace std;
FrequencySimulation::FrequencySimulation(void)
{
	results = new map<double, vector<complex<double>>*>;
	initFreq = 1;
	endFreq = 1000000;
	points = 10;

}


FrequencySimulation::~FrequencySimulation(void)
{
}

vector<complex<double>>* FrequencySimulation::solveEquationSystem(vector<vector<complex<double>>>& equationSystem) {
	unsigned long rows = equationSystem.size();
	unsigned long columns = equationSystem[0].size();

	unsigned long a;
	complex<double> biggest, pivot; //  nomes esclarecedores!


	for (unsigned long i = 1; i < rows; i++) {

		biggest = 0;
		a = i;

		for (unsigned long l = i; l < rows; l++) {         					//  percorre a matriz, da linha de interesse ao final,
			if (abs(equationSystem[l][i]) > abs(biggest)) { 	//  procurando qual é o maior valor na coluna de interesse
				a = l;					    				//  guarda em 'a', qual a linha do maior valor desta coluna
				biggest = equationSystem[l][i];					//	e em 't' qual o valor do maior elemento da coluna
			}												//  o valor de 'i' é que percorre as columns
		}
		if (i != a) {										// 'i' agora diz a linha em que estamos trabalhando
		  for (unsigned long l = 1; l < columns; l++) {					// coloca a linha com maior pivô para cima
			pivot = equationSystem[i][l];
			equationSystem[i][l] = equationSystem[a][l];
			equationSystem[a][l] = pivot;
		  }
		}

		if (abs(biggest) < tolerance) {
			//don't know what to do yet
			//singular matrix
		}

		for (unsigned long j = (columns - 1) ; j > 0; j--) {  /* Basta j>i em vez de j>0 */
		  equationSystem[i][j] /= biggest	;		  // divide um elemento pelo maior elemento de maior valor desta coluna, percorre da ultima coluna para a primeira
		  pivot=equationSystem[i][j];			  // guarda o valor do elemento já dividido em 'p'

		  for (unsigned long l = 1; l < rows; l++) {
			if (l != i)			  //remove das demais rows ('!i')
				equationSystem[l][j]-= (equationSystem[l][i]*pivot);
		  }
		}
	}

	cout << endl << "Matrix: " << endl;

	for(unsigned i = 1; i < rows; i++) {
		for(unsigned j = 1; j < columns; j++) {
			cout << real(equationSystem[i][j]) << "i" << imag(equationSystem[i][j]) << "  ";
		}
		cout << endl;
	}

	vector<complex<double>>* result;
	result = new vector<complex<double>>;
	for (unsigned long i = 1; i < rows; i++) {
		result->push_back(equationSystem[i][columns - 1]);
	}

	return result;
}

map<double,vector<complex<double>>*>* FrequencySimulation::simulateFrequencyResponse(ComponentStorage *componentStorage, double initialFrequency = 1, double endFrequency = 1000000, unsigned pointsPerOctave = 10) {

	delete results; //delete old results
	results = new std::map<double, std::vector<std::complex<double>>*>; //allocate new result
	
	double frequencyStep = pow(2.0,1.0/(pointsPerOctave));
	componentStorage->allocateNodeNumbers();
	unsigned long systemSize = componentStorage->getSystemSize();
	
	//holds the matrix that will be solved
	vector<vector<complex<double>>> equationSystem;

	for(double currentFrequency = initialFrequency; currentFrequency <= endFrequency; currentFrequency *= frequencyStep) {
		componentStorage->getFrequencySystem(&equationSystem, currentFrequency);
		(*results)[currentFrequency] = solveEquationSystem(equationSystem);
	}

	return results;
}

map<double,vector<complex<double>>*>* FrequencySimulation::simulateFrequencyResponse(ComponentStorage *componentStorage) {
	return simulateFrequencyResponse(componentStorage,initFreq,endFreq,points);
}

void FrequencySimulation::setParameters(double initial, double end, unsigned pointsPerOctave) {
	initFreq = initial;
	endFreq = end;
	points = pointsPerOctave;
}
