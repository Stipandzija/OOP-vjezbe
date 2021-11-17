#include <iostream>
#include "Header.hpp"
using namespace std;

int& funkcija(int* niz, int index, int v) {

        return niz[index];
}
