#ifndef DEALER_HPP_
#define DEALER_HPP_

#include "hand.hpp"
#include "deck.hpp"
#include "player.hpp"
#include <vector>
#include <string>

class dealer : public player {

public:
	dealer();
	void turn(deck&, int);
	virtual ~dealer();
};

#endif