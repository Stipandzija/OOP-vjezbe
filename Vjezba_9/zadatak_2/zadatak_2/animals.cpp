#include <iostream>
#include "dog.hpp"
#include "Counter.hpp"
#include "cat.hpp"
#include "tarantula.hpp"

using namespace std;

int main()
{
	animals::counter br;
	animals::dog d;
	animals::cat c;
	animals::tarantula t;
	
	br.add_legs(&d);
	br.add_legs(&c);
	br.add_legs(&t);
	cout << "ukupno nogu: " << br.get_legs() << endl;
}