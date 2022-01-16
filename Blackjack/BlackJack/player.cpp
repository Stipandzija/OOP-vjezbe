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
		cout << "Greska unjeli ste: " << stake << " iznos racuna: " << get_balance() << endl;
		put_stake(min_stake);
	}
	while (stake < min_stake) {
		stake = 0;
		cout << "Nedovoljno kredita za igru" << endl;
		cout << "Zelis li ponovo uloziti y / n: ";

		string x; getline(cin, x);
		cout << endl;
		if (x.length() == 0)
		{
			cout << "Greska niste unos: " << endl;
		}
		if (x == "y")
		{
			return put_stake(min_stake);
		}
		else if (x == "n") {
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
		cout << "Na racunu imate: " << get_balance() << endl;
		timer(3);
		system("cls");

		return stake;
	}
}
void player::set_ace_to_one(card c, int index) {
	for (int i = index; i < h.get_size(); i++) {
			if (h.get_card_value(i) != 0)
				break;
			else if ((h.get_card_rank(i) == "A") && ((h.get_score_of_hand() + 11) > 21)) {
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
				if (h.get_card_value(i) != 0)
					break;
				else if ((h.get_card_rank(i) == "A") && h.get_score_of_hand() < 21) {
					cout << "Unesite zeljenu vrijednost za asa 1 / 11" << endl;
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

	
	if (get_score() <= 17) {
		h.set_card_in_hand(c);
			for (int i = 0; i < h.get_size(); i++)
			{
		
				if ((h.get_card_rank(i) == "A") && (h.get_score_of_hand() > 11)) {

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
			cout << "******************************************************************************" << endl;

		here: //// ovjde se vraca

			cout << "Zelis li UDARITI ili STATI     " << endl;
			cout << "Za UDARITI stisni: y   " << endl;
			cout << "Za STATI stisni: n    " << endl;
			cout << ": ";
			string x; cin >> x;

			if ((x.size() > 1) && (x != "y") && (x != "n")) {

				cout << "Pogreska u unosenju" << endl;
				cout << "Pokusajte opet" << endl;
				goto here;

			}
			else if (x == "y") {

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
			else if (x == "n") {

				turn = false;
			}
			else;
		}
	}
}

void player::print_current_hand() {

	h.print_hand();

}

