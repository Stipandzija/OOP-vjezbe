#pragma once
#include <string>
using namespace std;

namespace animals
{
	class animal {
		public:
			virtual int get_number_of_legs() = 0;
			virtual string get_name() = 0;
			virtual ~animal() = default;
	};
}