#ifndef DECK_HPP_
#define DECK_HPP_

#include "card.hpp"
#include <vector>
#include <string>


using namespace std;

class deck {

	vector<string> suits;
	vector<string> ranks;
	vector<card> cards;
	int counter;
public:
	deck();

	void set_cards_ranks(); // postavlja decka damu kralju asa svih vrsta i daje vrj 10
	void set_cards_numb(); // postavlja karte od 2 - 10 svih vrsta
	void shuffle();
	void find_ace(); // mjenja vrijednost iz 10 u 11
	void create_deck() { set_cards_ranks(); set_cards_numb(); find_ace(); shuffle(); }

	void remove_cards();
	card give_to();
	virtual ~deck();
};
#endif