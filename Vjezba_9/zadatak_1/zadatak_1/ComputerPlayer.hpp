#pragma once
#include "Player.hpp"


namespace japaneza {
	class computer_player : public player{
		int current_points=0;
			public:
				void set_up_points() { current_points++; }
				int get_points() { return current_points; }
	};
}