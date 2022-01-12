#include "interface.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace animals {
	class cat : public animal {
		int number_of_l;
		string name;
	public:
		cat() { number_of_l = 4; name = "cat";}
		int get_number_of_legs() { return number_of_l; }
		string get_name() { return name; }
	};
}