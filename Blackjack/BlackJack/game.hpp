#ifndef GAME_HPP_
#define GAME_HPP_

#include "player.hpp"
#include <iostream>
#include "dealer.hpp"
#include "deck.hpp"
#include <vector>
#include <string>

using namespace std;

class game {
	int min_stake;
	int stakee;
	deck deck;
public:

	game() { min_stake = 20; };

	bool play();
	string player_name();
	int set_balance();

	void game_over() {
		cout << "         << thanks for playing >>         " << endl;
	}
	bool play_until();

	void start_game(player&, dealer&);

	void first_lap(player&, dealer&);
	void second_lap(player&, dealer&);



	void winner(player&, dealer&);
	void higher_score(player&, dealer&);

	virtual ~game();
};
#endif