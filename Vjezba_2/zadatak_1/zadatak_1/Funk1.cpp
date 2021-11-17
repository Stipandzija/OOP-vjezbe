#include <iostream>
#include "Funk1.h"

using namespace std;

int  unsoNiz(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	return 0;
}

void minMax(int *arr, int &min,int &max,int n) {

	int i;
	for (i = 0; i < n; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

}