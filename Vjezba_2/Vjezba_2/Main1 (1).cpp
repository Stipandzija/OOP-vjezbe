#include <iostream>
#include "Funk1.h"

using namespace std;

int main(void) {

	int n;
	int min=0, max=0;
	int arr[1000];
	cout << "Unesite velinu niza: \n" << endl;
	cin >> n;
	cout << "Uneiste niz: \n" << endl;
	unsoNiz(arr,n);
	min = arr[0];
	max = arr[0];
	minMax(arr, min, max,n);
	cout << "Najveci: \n" << max <<"\n" << "Najmanji: \n" << min << endl;

}