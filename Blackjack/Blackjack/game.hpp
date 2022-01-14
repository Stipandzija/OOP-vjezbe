#pragma once
#include "player.hpp"
#include "dealer.hpp"
#include "Deck.hpp"
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
		void game_start() { cout << " << dobrodosli u blackjack >>"; }
		void game_over() { cout << " << hvala na igranju >>"; }
		void start_game(player&, dealer&);
		void dijeljenje(player&, dealer&);

		void winner(player&, dealer&);
		void higher_score(player&, dealer&);
		void time(int);
		void timer(int);
		virtual ~game();
	};
