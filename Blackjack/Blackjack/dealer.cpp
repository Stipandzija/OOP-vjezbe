#include <iostream>
#include "dealer.hpp"



	dealer::dealer() {

	}
	dealer::~dealer() {

	}
	void dealer::turn(deck& d, int score)
	{
		while (get_score() < score)
		{
			hit(d.give_to());
		}
	}
