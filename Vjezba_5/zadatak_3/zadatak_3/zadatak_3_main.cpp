#include <iostream>
#include <stdbool.h>
#include "Header.hpp"

using namespace std;

int main()
{
	Point p1;
	Point p2;
	Point p;
	Meta m;
	int x = m.condition(p1, p2, p);
	if (x == 1)
		cout << "Pogodzena" << endl;
	else
		cout << "Promasena" << endl;
}