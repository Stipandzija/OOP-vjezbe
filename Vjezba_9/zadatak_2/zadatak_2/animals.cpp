#include <iostream>
#include "dog.hpp"
#include "Counter.hpp"
#include "cat.hpp"
#include "tarantula.hpp"
#include <vector>

using namespace std;

int main()
{
	animals::counter c;
	animals::dog d;
	animals::cat ca;
	animals::tarantula t;
	animals::animal *a;
	
	c.add_legs(&d);
	c.add_legs(&ca);
	c.add_legs(&t);
	cout << "ukupno nogu: " << c.get_legs() << endl;
}