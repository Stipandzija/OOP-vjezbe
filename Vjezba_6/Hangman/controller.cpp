#include "model.h"
#include <iostream>
#include <cctype>

using namespace std;


char Controller::user_entry() {
	char ret = 0;
	cin >> ret;
	return ret;
}
bool Controller::check_letter(Model& m, char c) {
	int counter = 0;
	for (int i = 0, sz = m.movie.size(); i < sz; ++i) {
		auto& x = m.movie[i];
		if (x == c || x == toupper(c)) {
			m.guess_movie[i] = c;
			++counter;
		}
	}
	return counter > 0;
}
void Controller::update_lives(Model& m) {
	if (!check_letter(m, (user_entry()))) m.lives--;
}
bool Controller::check_game_over(Model& m) {
	if (m.lives <= 0 || !m.in_game())
		cout << m.movie << endl;
	return m.lives <= 0 || !m.in_game();
}

