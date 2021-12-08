#include "controller.h"
#include <iostream>
#include <cctype>

using namespace std;

namespace Hangman {
	char Controller::user_entry() {
		char ret = 0;
		cin >> ret;
		return ret;
	}
	bool Controller::check_letter(char c) {
		int counter = 0;
		for (int i = 0, sz = movie.size(); i < sz;++i) {
			auto& x = movie[i];
			if (x == c || x==toupper(c)){
				guess_movie[i] = c;
				++counter;
			}
		}
		return counter > 0;
	}
	void Controller::update_lives() {
		if (!check_letter(user_entry())) --lives;
	}
	bool Controller::check_game_over() {
		if (lives <= 0 || !in_game())
			cout << movie << endl;
		return lives <= 0 || !in_game();
	}
}
