#include"card.hpp"
#include <iostream>

using namespace std;



	card::card(string suit, string rank, int value_rank) {

		this->suit = suit;
		this->rank = rank;
		this->value = value_rank;
	}
	card::~card() {

	}
	void card::set_suit(string suit) {
		this->suit = suit;
	}
	void card::set_rank(string rank) {
		this->rank = rank;
	}
	void card::set_value(int value) {
		this->value = value;
	}
	void card::set_numbers(int number) {
		rank = to_string(number);
	}

