#pragma once
#include <string>
using namespace std;

namespace Hangman {
	class Model {
	protected:
		int lives;
		string movie;
		string guess_movie;
	public:
		Model();
		bool in_game();
	};
}

