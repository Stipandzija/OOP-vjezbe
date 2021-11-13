#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	int x;
	cout << "unesi velicinu niza";
	cin >> x;
	int arr[1024], i;

	for (i = 0; i < x; i++) {
		cout << "Unesi broj u niz: " << endl;
		cin >> arr[i];
	}
	
	cout << "Najmanji je: "<< najmanji(arr, x) << endl;
	cout << "Najveci je: " << najveci(arr, x) << endl;

	

	return 0;
}