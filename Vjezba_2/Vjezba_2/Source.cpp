#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    int index = 0;
    int niz[] = { 3,4,2,6,8 };
    int n = 5;
    funkcija(niz, index, n)+=1;
    for (int i = 0; i < n; i++) {
        cout << niz[i] << endl;
    }
}