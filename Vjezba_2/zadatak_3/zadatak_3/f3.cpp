#include <iostream>
#include "Header.hpp"

using namespace std;

void UnosP(pravokutnik* niz, int n) {
	int i;
	for (i = 0; i < n; i++) {

		cout << "unesite pravokutnik" << endl;
		cout << "Stranica_a.x:";
		cin >> niz[i].a.x;
		cout << "Stranica_a.y:";
		cin >> niz[i].a.y;
		cout << "Stranica_b.x:";
		cin >> niz[i].b.x;
		cout << "Stranica_b.y:";
		cin >> niz[i].b.y;
	}

}
void UnosK(kruznica& k) {


	cout << "unesite radijus \n" << endl;
	cout << "r- ";
	cin >> k.r;
	cout << "tocka s.x-" << endl;
	cin >> k.s.x;
	cout << "tocka s.y-" << endl;
	cin >> k.s.y;

}
int  Presjek(kruznica& k, pravokutnik* niz, int n) {

	tocka t;
	int br = 0;
	for (int i = 0; i < n; i++) {
		t.x = k.s.x - max(niz[i].a.x, min(k.s.x, niz[i].a.x + (niz[i].b.x - niz[i].a.x)));
		t.y = k.s.y - max(niz[i].a.y, min(k.s.y, niz[i].a.y + (niz[i].b.y - niz[i].a.y)));

		if ((t.x * t.x + t.y * t.y) <= k.r * k.r) {

			br++;
		}
	}
	return br;
}

