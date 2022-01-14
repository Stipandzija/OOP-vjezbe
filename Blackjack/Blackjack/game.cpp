#include "game.hpp"
#include "Deck.hpp"
#include <iostream>
#include <cctype>
#include <Windows.h>


using namespace std;
game::~game() {

}
bool game::play() {

	dealer d;
	cout << endl;
	player p(player_name());
	cout << endl;
	p.set_balance(set_balance());
	cout << endl;
	cout << "_________________________________" << endl;
	cout << endl;
	
	while (1) {
		if (p.get_balance() < min_stake) {
			cout << "Nedovoljan balans" << endl;
			return false;
		}
		else if ((stakee=p.put_stake(min_stake)) > 0)
			start_game(p, d);
		else
			return false;
	}

}

string game::player_name() {
	cout << "Unesite vase ime: ";
	string s; getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (!isalpha(s[i])) {
			cout << "Greska u unosu, ponovite" << endl;
			player_name();
		}
	}
	return s;
}
int game::set_balance() {
	cout << "Unesite balans $: ";
	string x;
	getline(cin,x);
	for (int i = 0; i < x.size(); i++) {
		if (!isdigit(x[i]))
		{
			cout << "Greska u unosu, ponovite" << endl;
			set_balance();
		}
	}
	int value = stoi(x);
	return value;
}
void game::start_game(player& p, dealer& d) {

	deck.remove_cards();
	deck.create_deck();
	dijeljenje(p, d);
	cout << "Dealer dijeli: " << endl;
	cout << endl;
	timer(2);
	d.print_current_hand();
	cout << "Dealer- score: " << d.get_score() << endl;
	timer(2);
	cout <<"Igrac: "<< p.get_player_name() << " otvara:" << endl;
	//p.print_current_hand();
	p.round(deck);
	//stake = p.put_stake(min_stake);
	cout << "_________________________________" << endl;
	cout << "Dealer otkriva" << endl;
	d.open_card();
	cout << "Dealer - score: " << d.get_score() << endl;
	winner(p, d);
	p.clear_hand();
	d.clear_hand();

	cout << endl;
	cout << "Molim vas pricekajte 5s: ";
	cout << endl;
	time(5);
	cout << "_________________________________" << endl;
	cout << endl;
}

void game::dijeljenje(player& p, dealer& d) {
	p.hit(deck.give_to());
	p.hit(deck.give_to());
	d.dealer_hit(deck.give_to());
	d.dealer_hit(deck.give_to());
	d.hidden_card();
}
void game::time(int x) {
	
	while (x != 0) {
		cout << "Pricekajte: " << x << " sekudni." << endl;
		cout << endl;
		x--;
		Sleep(1000);
	}
}
void game::timer(int x) {

	while (x != 0) {
		x--;
		Sleep(1000);
	}
}
void game::winner(player& p, dealer& d) {
	if (p.get_score() > 21) {
		{
			cout<< p.get_player_name() << " uhvacen si." << endl;
			p.print_current_hand();
		}
	}

	d.turn(deck, p.get_score());
	cout<< "Dealer ima: " << endl;
	d.print_current_hand();
	higher_score(p, d);

}
void game::higher_score(player& p, dealer& d)
{
	if ((p.get_score()> d.get_score() || ((d.get_score())>21) && p.get_score()<=21))
	{	
		cout << endl;
		cout << "Vas score - " << p.get_score() << endl;
		cout<< " Ostvario si pobjedu " << endl;
		int n = (stakee * 2);
		cout <<"Dobio si: " << n << " $ kredita" << endl;
		p.win_game(n);
		cout << endl;
		cout << "Trenutni balans: " << p.get_balance() << endl;
		cout << endl;
		cout << "_________________________________" << endl;
	}
	else
	{
		cout << endl;
		cout << "Dealer je pobjedio" << endl;
		cout << endl;
		cout << "Dealer - score: " << d.get_score() << endl;
		cout << "Izgubio si: " << stakee << " $ kredita" << endl;
		cout << endl;
		cout << "Trenutni balans: " << p.get_balance() << endl;
		cout << endl;
		cout << "_________________________________" << endl;
	}
}