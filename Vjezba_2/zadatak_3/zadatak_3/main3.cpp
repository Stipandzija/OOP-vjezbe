#include <iostream>
#include "Header.hpp"

using namespace std;

int main()
{
	int broj, x;

	cout << "Unesite pravoktunike";
	cin >> x;
	pravokutnik* P;
	P = new pravokutnik[x];

	UnosP(P, x);
	kruznica k;
	UnosK(&k);
	broj = Presjek(k, P, x);


	cout << "\n" << broj << " presjeca";
}