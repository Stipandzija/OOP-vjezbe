#pragma once
#include <iostream>
#include "ComputerPlayer.hpp"
#include "HumanPlayer.hpp"
#include <vector>

using namespace std;

namespace japaneza {
	class game
	{
	private:
		vector<human_player> hp;
		computer_player cp;

		int dog_br_bodova;
		
		
			public:
				void add_player();
				void quess_sum();
				bool random_sum(int x,int y);
				bool if_game_over();
				void set_bod();
	};
}