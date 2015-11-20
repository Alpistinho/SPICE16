#include "stdafx.h"
#include "Simulation.h"

using namespace std;

Simulation::Simulation(void)
{
}


Simulation::~Simulation(void)
{
}


//solves the system and returns the result
vector<complex<double>> Simulation::solveEquationSystem() {

	unsigned long rows = equations + 1;
	unsigned long columns = equations + 2;

	unsigned long i,j,l, a;
	complex<double> biggest, pivot; //  nomes esclarecedores!

	results.clear();

	for (i = 1; i < rows; i++) {

		biggest = 0;
		a = i;

		for (l = i; l < rows; l++) {         					//  percorre a matriz, da linha de interesse ao final,
			if (abs(equationSystem[l][i]) > abs(biggest)) { 	//  procurando qual é o maior valor na coluna de interesse
				a = l;					    				//  guarda em 'a', qual a linha do maior valor desta coluna
				biggest = equationSystem[l][i];					//	e em 't' qual o valor do maior elemento da coluna
			}												//  o valor de 'i' é que percorre as columns
		}
		if (i != a) {										// 'i' agora diz a linha em que estamos trabalhando
		  for (l = 1; l < columns; l++) {					// coloca a linha com maior pivô para cima
			pivot = equationSystem[i][l];
			equationSystem[i][l] = equationSystem[a][l];
			equationSystem[a][l] = pivot;
		  }
		}

		if (abs(biggest) < tolerance) {
			//don't know what to do yet
			//singular matrix
		}

		for (j = (columns - 1) ; j > 0; j--) {  /* Basta j>i em vez de j>0 */
		  equationSystem[i][j] /= biggest	;		  // divide um elemento pelo maior elemento de maior valor desta coluna, percorre da ultima coluna para a primeira
		  pivot=equationSystem[i][j];			  // guarda o valor do elemento já dividido em 'p'

		  for (l = 1; l < rows; l++) {
			if (l != i)			  //remove das demais rows ('!i')
				equationSystem[l][j]-= (equationSystem[l][i]*pivot);
		  }
		}
	}
	vector<complex<double>> result;
	for (i = 1; i < rows; i++) {
		result.push_back(equationSystem[i][columns - 1]);
	}

	return result;
}