#pragma once
#include "interface.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace animals {
	class tarantula : public animal {
		int number_of_l;
		string name;
	public:
		tarantula() { number_of_l = 8; name = "tarantula"; }
		int get_number_of_legs() { return number_of_l; }
		string get_name() { return name; }

	};
}