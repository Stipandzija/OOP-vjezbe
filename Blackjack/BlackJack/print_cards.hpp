#ifndef PLAYER_CARDS_HPP_
#define PLAYER_CARDS_HPP_

#include <string>
#include <vector>

using namespace std;

class print {

	vector<string> heart;
	vector<string> club;
	vector<string> spade;
	vector<string> diamond;
	vector<string> hidden_card;
	vector<string> print_top_bot;

public:
	print();
	string club_symbol(int x) { return club[x]; }
	string heart_symbol(int x) { return heart[x]; }
	string diamond_symbol(int x) { return diamond[x]; }
	string spade_symol(int x) { return spade[x]; }
	string hidden_symol(int x) { return hidden_card[x]; }

	string get_header(int x) { return print_top_bot.at(x); }

	string print_card(string, int);

	string top_rank(string);
	string bot_rank(string);

	int get_sizee() { return print_top_bot.size(); }

	virtual ~print();
};
#endif
