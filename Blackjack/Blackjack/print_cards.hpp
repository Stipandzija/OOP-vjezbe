#pragma once
#include <string>
#include <vector>

using namespace std;

class print {
	
	vector<string> heart;
	vector<string> club;
	vector<string> spade;
	vector<string> diamond;
	vector<string> hidden_card;

	public:
		print();
		string club_symbol(int x) { return club[x]; }
		string heart_symbol(int x) { return heart[x]; }
		string diamond_symbol(int x) { return diamond[x]; }
		string spade_symol(int x) { return spade[x]; }
		string hidden_symol(int x) { return hidden_card[x]; }

		string print_card(string, int);
		virtual ~print();
};