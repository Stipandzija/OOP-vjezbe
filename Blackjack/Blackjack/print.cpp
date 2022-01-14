#include "print_cards.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

print::print() {
	club.push_back(" ___________ ");
	club.push_back("/           \\");
	club.push_back("|     _     |"); 
	club.push_back("|    (_)    |");
	club.push_back("|   (_)_)   |");
	club.push_back("|    /_\\    |");
	club.push_back("|           |");
	club.push_back("\\__________/");

	heart.push_back(" ___________");
	heart.push_back("/           \\");
	heart.push_back("|    _ _    |"); 
	heart.push_back("|   /   \\   |");
	heart.push_back("|   \\   /   |");
	heart.push_back("|    \\ /    |");
	heart.push_back("|           |"); 
	heart.push_back("\\__________/");

	spade.push_back(" ___________ ");
	spade.push_back("/           \\");
	spade.push_back("|           |");
	spade.push_back("|    / \\    |");
	spade.push_back("|   (_ _)   |");
	spade.push_back("|    /_\\    |");
	spade.push_back("|           |");   
	spade.push_back(" \\_________/");

	diamond.push_back(" ____________ ");
	diamond.push_back("/            \\");
	diamond.push_back("|            |");
	diamond.push_back("|     /\\     |");
	diamond.push_back("|    <  >    |");
	diamond.push_back("|     \\/     |");
	diamond.push_back("|            |");
	diamond.push_back("\\___________/");

	hidden_card.push_back(" ___________ ");
	hidden_card.push_back("/           \\");
	hidden_card.push_back("|            |");  
	hidden_card.push_back("|    .??.    |");
	hidden_card.push_back("|   HIDDEN   |");
	hidden_card.push_back("|    .??.    |");
	hidden_card.push_back("|            |");
	hidden_card.push_back("\\___________/");
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

