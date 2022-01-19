#include "player.hpp"
#include <iostream>
#include "other_functions.hpp"
#include <string>

using namespace std;


player::player() {

}
player::player(string s) {
	player_name = s;
	balance = 0;
}
player::~player() {

}
int player::put_stake(int min_stake) {

	stake = 0;
	stake = stake_correct_input();
	bool b = false;

	if (stake > get_balance())
	{
		cout << "You entered an input error " << stake << " current balance: " << get_balance() << endl;
		return put_stake(min_stake);
	}
	while (stake < min_stake) {
		stake = 0;
		cout << "Not enough credit for the game" << endl;
		cout << "Set credit: ";

		string x; getline(cin, x);
		cout << endl;
		if (x.length() == 0)
		{
			cout << "Input error: " << endl;
			return put_stake(min_stake);
		}
		if (x == "yes")
		{
			return put_stake(min_stake);
		}
		else if (x == "no") {
			b = true;
			break;
		}
		else {
			b = true;
			break;
		}
	}
	if (b == true) {

		return 0;

	}else {

		cout << endl;
		balance -= stake;
		timer(2);
		system("cls");

		return stake;
	}
}
void player::set_ace_to_one(card c, int index) {
	for (int i = index; i < h.get_size(); i++) {
			if ((h.get_card_rank(i) == "A") && ((h.get_score_of_hand() + 11) > 21)) {
				if (h.get_card_value(i) != 0)
					break;
				h.set_card_value(i, 1);
				break;
			}else ;
	}
}
void player::player_hit(card c) {

	
	if (get_score() < 21) {
		h.set_card_in_hand(c);
		print_current_hand();
		for (int i = 0; i < h.get_size(); i++) {
				if ((h.get_card_rank(i) == "A") && h.get_score_of_hand() < 21) {
					if (h.get_card_value(i) != 0)
							break;
					cout << "Enter the desired value for aces 1/11" << endl;
					cout << ": ";
					int x; cin >> x; h.set_card_value(i, x);
					cout << endl;
				}
				else {
					set_ace_to_one(c, i);
				}
		}
	}
}
void player::dealer_hit(card c) {

	
	if (get_score() <17) {
		h.set_card_in_hand(c);
			for (int i = 0; i < h.get_size(); i++)
			{
		
				if ((h.get_card_rank(i) == "A") && (h.get_score_of_hand() > 21)) {

					h.set_card_value(i, 1);
				}
				else if ((h.get_card_rank(i) == "A") && (h.get_score_of_hand() < 11)) {
					h.set_card_value(i, 11);
				}
				else ;
				
			}
	}
}
void player::player_round(deck& d) {

	bool turn = true;
	while (turn)
	{
		if (get_score() == 21) {
			turn = false;
			break;
		}
		else if (get_score() > 21) {

			turn = false;
			break;
		}
		else {
			string x;
			bool f = false;
			while (!f) {
				x.clear();
				cout << "Do you want to HIT or STAND    " << endl;
				cout << "HIT - press: yes   " << endl;
				cout << "STAND - press: no    " << endl;
				cout << ": ";
				cin >> x;

				if ((x.size() > 1) && (x != "yes") && (x != "no")) {

					cout << "Input error" << endl;
					cout << "Try again "<< endl;
					f = false;
				}
				else
					f = true;
			}
			if (x == "yes") {

				if (get_score() == 21) {

					turn = false;
					break;

				}
				else if (get_score() < 21) {
					player_hit(d.give_to());
					cout << get_player_name() << " - score: " << get_score() << endl;
					turn = true;

				}
				else {
					turn = false;
					break;
				}

			}
			else if (x == "no") {

				turn = false;
			}
			else;
		}
	}
}

void player::print_current_hand() {

	h.print_hand();

}

