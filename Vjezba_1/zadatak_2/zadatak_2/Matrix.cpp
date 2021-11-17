#include "Header.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
 
using namespace std;


int main()
{
	int m, n;
	cout << "Unesi dimenziju matrice" << endl;
	cin >> m;
	cout << "Unesi dimenziju matrice" << endl;
	cin >> n;

	Matrica A = Matrica::input(m, n);
	int a, b;
	
	cout << "Unesi granice a, b" << endl;
	cin >> a;
	cin >> b;
	Matrica B = Matrica::generate(m, n, a, b);
	Matrica zbroj = Matrica::sum(A,B,m,n);

	Matrica razlika = Matrica::sub(A, B, m, n);;

	Matrica umnozak = Matrica::mult(A, B, m, n);
	print(B,m,n);

	return 0;
}