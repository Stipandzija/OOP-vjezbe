#include <iostream>
#include "funk.h"

using namespace std;

void unosNiza(int* niz) {

	int i;
	for (i = 0; i < 10; i++) {
		cin >> niz[i];
	}
}

void minMax(int* niz){

	int min, max, i;
	min = niz[0];
	max = niz[0];
	for (i = 0; i < 10; i++) {
		if (niz[i] < min)
			min = niz[i];
		if (niz[i] > max)
			max = niz[i];
	}
	cout << min << "   " << max << endl;
}
