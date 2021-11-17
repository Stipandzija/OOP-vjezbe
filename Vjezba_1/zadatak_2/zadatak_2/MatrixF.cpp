#include "Header.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>


using namespace std;

Matrica Matrica::input(int redak, int stupac)
{
	Matrica matrica;
	matrica.redak = redak;
	matrica.stupac = stupac;
	matrica.m = new float* [redak];

	for(int i=0;i < redak; i++) 
		matrica.m[i] = new float[stupac];

	cout << "Unesi elemente u matricu: " << endl;
	
	for (int i=0; i < redak ;i++) 
	{
		for (int j = 0; j < stupac; j++)
		{
			cin >> matrica.m[i][j];
		}
	}
	cout << endl;
	
	return matrica;
}
Matrica Matrica::generate(int redak, int stupac, int a, int b)
{
	srand(time(NULL));
	Matrica matrica;
	matrica.redak = redak;
	matrica.stupac = stupac;
	matrica.m = new float* [redak];
	for (int i = 0; i < redak;i++) {
		matrica.m[i] = new float[stupac];
	}
	for(int i=0;i < redak; i++){
		for (int j = 0; j < stupac; j++) {
			matrica.m[i][j] = a + (rand() % (b - a + 1));
		}
	}
	return matrica;
}
Matrica Matrica::sum(Matrica matrica1, Matrica matrica2, int redak, int stupac)
{
	Matrica matrica;
	matrica.redak = redak;
	matrica.stupac = stupac;
	matrica.m = new float* [redak];
	for (int i = 0; i < redak; i++) {
		matrica.m[i] = new float[stupac];
	}
	for (int i = 0; i < redak; ++i) {
		for (int j = 0; j < stupac; ++j) {
			matrica.m[i][j] = (matrica1.m[i][j] + matrica2.m[i][j]);
		}
	}
	return matrica;
}
Matrica Matrica::sub(Matrica matrica1, Matrica matrica2, int redak, int stupac)
{
	Matrica matrica;
	matrica.redak = redak;
	matrica.stupac = stupac;
	matrica.m = new float* [redak];
	for (int i = 0; i < redak; i++) {
		matrica.m[i] = new float[stupac];
	}
	for (int i = 0; i < redak; i++) {
		for (int j = 0; j < stupac; j++) {
			matrica.m[i][j] = (matrica1.m[i][j] - matrica2.m[i][j]);
		}
	}
	return matrica;
}
Matrica Matrica::mult(Matrica matrica1, Matrica matrica2, int redak, int stupac)
{
	Matrica matrica;
	matrica.redak = redak;
	matrica.stupac = stupac;
	matrica.m = new float* [redak];
	for (int i = 0; i < redak; i++) {
		matrica.m[i] = new float[stupac];
	}
	for (int i = 0; i < redak; i++) {
		for (int j = 0; j < stupac; j++) {
			matrica.m[i][j] = (matrica1.m[i][j] * matrica2.m[i][j]);
		}
	}
	return matrica;
}
void print(Matrica matrica,int redak, int stupac)
{
	for (int i = 0; i < redak; i++) {
		for (int j = 0; j < stupac; j++) {
			cout << fixed << setprecision(4) << right << matrica.m[i][j] << " ";
		}
		cout << endl;
	}
}
