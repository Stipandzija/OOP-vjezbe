#include "game.hpp"
#include "deck.hpp"
#include <iostream>
#include <ctype.h>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include "other_functions.hpp"

using namespace std;



game::~game() {

}
bool game::play() {

	game_intro();
	dealer d;
	player p(player_name());
	p.set_balance(set_balance());
	bool b = false;;
	while (!b) {
		system("cls");
		game_header();
		if (p.get_balance() < min_stake) {
			cout << "Nedovoljan balans " << endl;
			p.set_balance(set_balance());
			timer(3);
			system("cls");
		}
		else if ((stakee = p.put_stake(min_stake)) > 0) {
			start_game(p, d);
			b = play_until();
		}
	}
	return false;
}

bool game::play_until() {
	string s;
	cout << "Zelis li nastaviti yes / no" << endl;
	cin >> s;
	if (s.length() == 0)
		return play_until();
	for (int i = 0; i < s.length(); i++) {
		if (!isalpha(s.at(i))) {
			cout << "Greska u unosu unjeli ste: '" << s << "' ponovite unos" << endl;
			return play_until();
		}
	}
	if (s == "yes")
		return false;
	else if (s == "no")
		return true;
	else {
		cout << "Pokreska u unosu unjeli ste: '" << s << "' ponovite unos" << endl;
		return play_until();
	}
}
string game::player_name() {


	string s;
	cout << "Unesite vase ime:  ";
	cin >> s;
	if (s.length() == 0)
		return player_name();
	for (int i = 0; i < s.length(); i++) {
		if (!isalpha(s.at(i))) {
			cout << "Greska u unosu unjeli ste: '" << s << "' ponovite unos" << endl;
			return player_name();
		}
	}
	return s;
}
int game::set_balance() {

	cout << "Unesite balans $: ";
	string s;
	cin >> s;
	if (s.length() == 0)
		return set_balance();
	for (int i = 0; i < s.length(); i++) {
		if (!isdigit(s.at(i)))
		{
			cout << "Greska u unosu unjeli ste: '" << s << "' ponovite unos " << endl;
			return set_balance();
		}
	}
	if (s.length() > 13) {
		cout << "Prevelik iznos, unesi ponovo " << endl;// na prevelikom unosu -858993460 = 0xCCCCCCCC pristupam neinicijaliziranoj memoriji
		return set_balance();
	}
	int value;
	value = stoi(s);
	return value;
}
void game::first_lap(player& p, dealer& d) {
	game_header();
	cout << p.get_player_name() << " - card   " << endl;
	p.player_hit(deck.give_to());
	cout << "******************************************************************************" << endl;
	cout << "Dealer - card" << endl;
	d.dealer_hit(deck.give_to());
	d.hidden_card();
	d.print_current_hand();
	cout << endl;
	cout << "Dealer- score: " << d.get_score() << endl;
	cout << "******************************************************************************" << endl;
	timer(3);

}
void game::second_lap(player& p, dealer& d) {
	cout << p.get_player_name() << " - card " << endl;
	cout << endl;
	p.player_hit(deck.give_to());
	cout << p.get_player_name() << " - score: " << p.get_score() << endl;
	cout << endl;
	cout << "******************************************************************************" << endl;
	cout << "Dealer - card" << endl;
	d.dealer_hit(deck.give_to());
	d.print_current_hand();
	cout << endl;
	cout << "Dealer- score: " << d.get_score() << endl;

}
void game::start_game(player& p, dealer& d) {

	deck.remove_cards();
	deck.create_deck();

	first_lap(p, d);
	second_lap(p, d);
	d.open_card();
	p.player_round(deck);
	winner(p, d);
	timer(2);
	p.clear_hand();
	d.clear_hand();
	cout << " Pricekajte 10s: " << endl;
	cout << "******************************************************************************" << endl;
	timer(5);
	time(5);
	system("cls");
}


void game::winner(player& p, dealer& d) {
	system("cls");
	if (p.get_score() == 21) {
		game_header();
		p.print_current_hand();
		cout << "Score - " << p.get_score() << endl;
		cout << " !!!! Blackjack !!!!" << endl;
		int n = (stakee * 2);
		cout << "Dobio si: " << n << " $ kredita " << endl;
		cout << "" << endl;
		timer(2);
		p.win_game(n);
		cout << "Trenutni balans: " << p.get_balance() << endl;
		cout << "******************************************************************************" << endl;

	}
	else if (p.get_score() > 21) {
		{
			game_header();
			p.print_current_hand();
			cout << "Vas score - " << p.get_score() << endl;
			cout << endl;
			cout << "Premasio si 21 " << endl;
			cout << "Izgubio si: " << stakee << " $ kredita " << endl;
			cout << "Trenutni balans: " << p.get_balance() << endl;
			timer(2);
			cout << endl;
		}
	}
	else {
		higher_score(p, d);
	}

}
void game::higher_score(player& p, dealer& d)
{
	if ((p.get_score() > d.get_score() || ((d.get_score()) > 21) && p.get_score() < 21))
	{
		system("cls");
		game_header();
		p.print_current_hand();
		cout << "Vas score - " << p.get_score() << endl;
		d.print_current_hand();
		cout << "Dealer - score: " << d.get_score() << endl;
		cout << endl;
		cout << "Ostvario si pobjedu " << endl;
		int n = (stakee * 2);
		cout << "Dobio si: " << n << " $ kredita " << endl;
		cout << "" << endl;
		p.win_game(n);
		cout << "Trenutni balans: " << p.get_balance() << endl;
		cout << "******************************************************************************" << endl;
		timer(2);
	}
	else
	{
		system("cls");
		game_header();
		p.print_current_hand();
		cout << "Vas score - " << p.get_score() << endl;
		cout << endl;
		d.print_current_hand();
		cout << "Dealer - score: " << d.get_score() << endl;
		cout << "" << endl;
		cout << "Dealer je pobjedio " << endl;
		cout << "" << endl;
		cout << "Izgubio si: " << stakee << " $ kredita " << endl;
		cout << "" << endl;
		cout << "Trenutni balans: " << p.get_balance() << endl;
		cout << "" << endl;
		cout << "******************************************************************************" << endl;
		timer(2);
	}
}

