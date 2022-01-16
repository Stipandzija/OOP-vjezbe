#include "print_cards.hpp"
#include <iostream>
#include <vector>
#include <string>


using namespace std;


print::print() {
	
	hidden_card.push_back("|            |");
	hidden_card.push_back("|    .??.    |");
	hidden_card.push_back("|   HIDDEN   |");
	hidden_card.push_back("|    .??.    |");
	hidden_card.push_back("|            |");

	heart.push_back("|    _ _    |");
	heart.push_back("|   /   \\   |");
	heart.push_back("|   \\   /   |");
	heart.push_back("|    \\ /    |");
	heart.push_back("|           |");
	



	spade.push_back("|           |");
	spade.push_back("|    / \\    |");
	spade.push_back("|   (_ _)   |");
	spade.push_back("|    /_\\    |");
	spade.push_back("|           |");

	
	club.push_back("|     _     |");
	club.push_back("|    (_)    |");
	club.push_back("|   (_)_)   |");
	club.push_back("|    /_\\    |");
	club.push_back("|           |");
	


	diamond.push_back("|            |");
	diamond.push_back("|     /\\     |");
	diamond.push_back("|    <  >    |");
	diamond.push_back("|     \\/     |");
	diamond.push_back("|            |");
	
	print_top_bot.push_back("_____________");

}
print::~print() {

}
string print::print_card(string s, int x) {
	if (s == "hearts") { return heart_symbol(x); }
	else if (s == "spades") { return spade_symol(x); }
	else if (s == "clubs") { return club_symbol(x); }
	else if (s == "diamonds") { return diamond_symbol(x); }
	else if (s == "hidden") { return hidden_symol(x); }

	return "Greska";
}
string print::bot_rank(string s) {
	string ss;
	ss.push_back('|');
	for (int i = 0; i < 9; ++i)
		ss.push_back(' ');
	if (s.length() == 2) {
		ss.push_back(s[0]);
		ss.push_back(s[1]);
		ss.push_back('|');
		return ss;
	}
	else {
		ss.push_back(' ');
		ss.push_back(s[0]);
		ss.push_back('|');
		return ss;
	}
}

string print::top_rank(string s) {
	string ss;
	ss.push_back('|');
	if (s.length() == 2) {
		ss.push_back(s[0]);
		ss.push_back(s[1]);
		for (int i = 0; i < 9; ++i)
			ss.push_back(' ');
		ss.push_back('|');
	}
	else {
		ss.push_back(s[0]);
		for (int i = 0; i < 10; ++i)
			ss.push_back(' ');
		ss.push_back('|');
	}


	return ss;
}
