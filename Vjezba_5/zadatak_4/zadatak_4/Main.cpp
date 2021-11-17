#include <iostream>
#include <time.h>
#include <stdbool.h>
#include "Header.hpp"

using namespace std;

int main()
{
	srand(time(NULL));
	Weapon w;
	int n = 1000000;
	Meta* m = new Meta[n];
	int br = 0;
	for(int j = 0; j < n ; j++)
	{
		int privremena = 0;
		privremena = w.rotate(m[j]);
		if (privremena == 0) {
			cout << "Nestalo metaka" << endl;
			break;
		}
		if(privremena == 2)
			br += (privremena-1);
	}
	cout << " " << endl;
	cout << "Pogodilo je: " << br << " meta" << endl;
	delete [] m;
}