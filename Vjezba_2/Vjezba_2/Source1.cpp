#include <iostream>
#include "Header.h"
using namespace std;

int& funkcija(int* niz, int index, int v) {

        return niz[index];
}
