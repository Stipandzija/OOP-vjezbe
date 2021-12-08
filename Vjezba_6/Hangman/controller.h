#pragma once
#include "model.h"

using namespace std;

namespace Hangman {
	class Controller : public Model
	{
	protected:
		char user_entry();
		bool check_letter(char c);
	public:
		void update_lives();
		bool check_game_over();
	};
}
