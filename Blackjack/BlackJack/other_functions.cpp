#include "other_functions.hpp"
#include<iostream>
#include<string>
#include<algorithm>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>

using namespace std;

void game_intro() {
	cout << "******************************************************************************" << endl;
	cout << "*                            Dobrodosli u Blackjack                          *" << endl;
	cout << "*                                                                            *" << endl;
	cout << "******************************************************************************" << endl;
}
void game_header() {
	cout << "******************************************************************************" << endl;
	cout << "*                                   Blackjack                                *" << endl;
	cout << "*                                                                            *" << endl;
	cout << "******************************************************************************" << endl;
}
void timer(int x) {

	while (x != 0) {
		x--;
		Sleep(1000);
	}
}

void time(int x) {

	while (x != 0) {
		system("cls");
		cout << "Pricekajte: " << x << " sekudni." << endl;
		x--;
		Sleep(1000);
	}
}
int stake_correct_input() {
	string x;
	cout << endl;
	cout << "Unesi kredit za pocetak kruga: ";
	cin >> x;
	cout << endl;

	if (x.length() == 0)
		return stake_correct_input();
	for (int i = 0; i < x.length(); i++) {
		if (!isdigit(x[i]))
		{
			cout << "Greska u unosu unjeli ste: '" << x << "' ponovite unos npr.123" << endl;
			return stake_correct_input();
		}
	}
	if (x.length() > 13) {
		cout << "Prevelik iznos, unesi ponovo " << endl;// na prevelikom unosu -858993460 = 0xCCCCCCCC pristupam neinicijaliziranoj memoriji
		return stake_correct_input();
	}

	
	
	int value = stoi(x);
	return value;
}
