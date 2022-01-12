#include "interface.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace animals {
	class dog : public animal {
		int number_of_l;
		string name;
		public:
			dog() { number_of_l = 4; name = "dog";}
			int get_number_of_legs() { return number_of_l; }
			string get_name() { return name; }
	};
}