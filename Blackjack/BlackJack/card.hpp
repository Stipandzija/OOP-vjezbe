#ifndef CARD_HPP_
#define CARD_HPP_


#include <string>
#include <iostream>
using namespace std;

class card
{

	int value;
	string suit;
	string rank;
	bool turned = false;


public:
	card(string, string, int);
	card(string s, int n, int x) { this->suit = s; set_numbers(n); this->value = x; };
	void set_suit(string);
	void set_rank(string);
	void set_value(int);

	void set_numbers(int);
	string get_suit() { return suit; }
	string get_rank() { return rank; }
	int get_value() { return value; }

	bool check_is_turned() { return turned; }
	void set_turned(bool n) { this->turned = n; }
	virtual ~card();
};
#endif