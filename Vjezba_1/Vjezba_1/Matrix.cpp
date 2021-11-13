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

	Matrica A;
	A.input(m, n);
	//int a, b;
	/*Matrica B, C;
	cout << "Unesi granice a, b" << endl;
	cin >> a;
	cin >> b;
	B.generate(2, 3, 1, 10);
	C.generate(2, 3, 1, 10);
	Matrica zbroj;
	zbroj.sum(B, C, 2, 3);

	Matrica razlika;
	razlika.sub(B, C, m, n);

	Matrica umnozak;
	umnozak.mult(B, C, m, n);
	*/
	print(A,m,n);

	return 0;
}