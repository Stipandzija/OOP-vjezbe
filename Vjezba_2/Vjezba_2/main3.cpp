#include <iostream>
#include "Header.hpp"

using namespace std;

int main()
{

	int broj;
	int x;

	cout << "Unesite pravokutnike:";
	cin >> x;
	pravokutnik* P;
	kruznica k;
	P = new pravokutnik[x];

	UnosP(P, x);
	UnosK(&k);
	broj = Presjek(k, P, x);


	cout << "\n" << broj << " -pravokutnika presjeca";
}