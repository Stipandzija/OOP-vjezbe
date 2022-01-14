#include "Deck.hpp"
#include <iostream>
#include <vector>
#include <algorithm> 
#include "Card.hpp"
#include <time.h>

using namespace std;


	deck::deck() {
		ranks.push_back("J");
		suits.push_back("hearts");
		ranks.push_back("Q");
		ranks.push_back("K");
		suits.push_back("diamonds");
		ranks.push_back("A");
		suits.push_back("clubs");
		suits.push_back("spades");


		counter = 0;
	}
	deck::~deck() {

	}
	void deck::remove_cards() {
		cards.clear();
	}
	void deck::shuffle() {
		srand(time(NULL));
		random_shuffle(cards.begin(), cards.end());
	}
	void deck::set_cards_ranks() {
		for (int i = 0; i < suits.size(); i++) {
			for (int j = 0; j < ranks.size(); j++) {
				card c(suits[i], ranks[j], 10);
				cards.push_back(c);
			}
		}
	}
	void deck::set_cards_numb() {
		for (int i = 0; i < suits.size(); i++) {
			for (int j = 2; j <= 10; j++) {
				card c(suits[i], j, j);
				cards.push_back(c);
			}
		}
	}
	void deck::find_ace() {

		for (auto& el : cards) {
			if (el.get_rank() == "A")
				el.set_value(11);
		}

	}

	card deck::give_to() {

		if (counter > cards.size())
			counter = 0;
		return cards[counter++];


	}
