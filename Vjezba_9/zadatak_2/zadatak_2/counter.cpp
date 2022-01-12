#include <iostream>
#include "Counter.hpp"
#include "interface.hpp"

using namespace std;
namespace animals {
	void counter::add_legs(animal* a) {
		count += a->get_number_of_legs();
		print_name(a);
	};
	void counter::print_name(animal* a)
	{
		cout << "dodan: " << a->get_name() << endl;
	}
}
