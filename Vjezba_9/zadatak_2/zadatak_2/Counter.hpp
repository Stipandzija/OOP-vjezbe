#pragma once
#include "Animal.hpp"
namespace animals {
	class counter {
		int count;
			public:
				counter() { count = 0; }
				void add_legs(animal*);
				void print_name(animal*);
				int get_legs() { return count; }
	};
}