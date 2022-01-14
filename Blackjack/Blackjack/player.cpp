#include "player.hpp"
#include <iostream>
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
	this->stake = 0;
	cout << "Unesi kredit: ";
	cin >> stake;
	bool b = false;
	while (stake <= min_stake) {
		stake = 0;
		cout << "Nedovoljno kredita za igru" << endl;
		cout << "Zelis li ponovo uloziti y / n: ";
		char x; cin >> x;
		cout << endl;
		if (x == 'y')
		{
			cout << "Koliko zelite uloziti: ";
			cin >> this->stake;
			cout << endl;
		}
		else {
			b = true;
			break;
		}

	}
		if (b == true) {
			return -1;
		}
	
	cout << endl;
	balance -= stake;
	cout << "Na racunu imate:" << get_balance() << endl;
	cout << endl;
	cout << "_________________________________" << endl;
	return stake;
}
void player::set_ace_to_one(card c,int index) {
	for (int i = index; i < h.get_size(); i++) {
		if ((h.get_card_rank(i) == "A") && ((h.get_score_of_hand() + 11) > 21)) {
			h.set_card_value(i, 1);
		}
		else if(h.get_card_rank(i) == "A"){
			cout << "Unesite zeljenu vrijednost za asa 1 / 11"<<endl;
			cout << ": ";
			int y; cin >> y; h.set_card_value(i,y);
			cout << endl;
		}
	}
}
void player::hit(card c) {

	h.set_card_in_hand(c);
	if (get_score() < 21) {
		for (int i = 0; i < h.get_size(); i++) {
			if (( h.get_card_rank(i) == "A") && (h.get_size() == 1)) {
				cout<<"Unesite zeljenu vrijednost za asa 1 / 11"<<endl;
				cout << ": ";
				int x; cin >> x; h.set_card_value(i,x);
				cout << endl;
			}else 
				set_ace_to_one(c,i);
		}
	}
}
void player::dealer_hit(card c) {
	h.set_card_in_hand(c);
	if (get_score() < 21) {
		for (int i = 0; i < h.get_size(); i++) {
			for (int i = 0; i < h.get_size(); i++)
			{
				if (h.get_card_rank(i) == "A" && h.get_card_value(i) == 11)
				{
					h.set_card_value(i, 1);
				}
			}
		}
	}
}
void player::round(deck& d) {

		bool turn = true;
		while (turn)
		{
			print_current_hand();
			cout << "Score: " << get_score() << endl;
			cout << endl;
			cout << "_________________________________" << endl;
			here:
			cout << "Zelis li UDARITI ili STATI" << endl;
			cout << endl;
			cout << "Za UDARITI stisni: y " << endl;
			cout << "Za STATI stisni: n" << endl;
			char x; cin >> x;
			if (x == 'y')
			{
				hit(d.give_to());
				
				if (get_score() <= 21)
					turn = true;
				else
				{
					turn = false;
				}
			}
			else if(x=='n') {
				
				turn = false;
			}
			else {
				cout << "Pogreska u unosenju" << endl;
				cout << "Pokusajte opet" << endl;
				goto here;
			}
		}
	}
	

void player::print_current_hand(){
	h.print_hand();
}

