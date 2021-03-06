#ifndef HAND_HPP_
#define HAND_HPP_

#include "card.hpp"
#include <iostream>
#include <vector>
#include "print_cards.hpp"

using namespace std;

class hand {

	vector<card> h;
	int score_of_hand;
	int score;
	void print_sym(print&);

	void print_top_rank(print&);
	void print_bot_rank(print&);
	void print_top_bot(print&);
public:
	hand();
	void set_card_in_hand(card c) { score = 0; h.push_back(c); }
	int get_size() { return h.size(); }

	int get_score_of_hand();

	void hidden(int next) { h[next].set_turned(true); }
	void open_card(int next) { h[next].set_turned(false); }

	int get_card_value(int x) { return h[x].get_value(); }
	string get_card_rank(int x) { return h[x].get_rank(); }
	void set_card_value(int x, int value) { h[x].set_value(value); }

	void print_hand();
	void clear_hand() { h.clear(); }


	
	virtual ~hand();
};

#endif