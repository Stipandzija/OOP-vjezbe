#pragma once
#include "deck.hpp"
#include "hand.hpp"
#include "card.hpp"

using namespace std;

class player {

	hand h;
	string player_name;

	int balance;
	int stake;


	public:
		player();
		player(string);
		string get_player_name() { return player_name; }

		void set_balance(int amount) { balance += amount; }
		int get_balance() { return balance; }
		void loss_game(int stake) { balance -= stake; }
		void win_game(int stake) { balance += stake; }

		int get_score() { return h.get_score_of_hand(); }
		int put_stake(int x);

		void hidden_card() { h.hidden(0); }
		void open_card() { h.open_card(0); }

		void hit(card);
		void dealer_hit(card);
		void set_ace_to_one(card, int);

		void print_current_hand();
		void round(deck&);

		void clear_hand() { h.clear_hand(); }

		virtual ~player();
};


