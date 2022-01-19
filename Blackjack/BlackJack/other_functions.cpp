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
	cout << "*                            Welcome to Blackjack                            *" << endl;
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
		cout << "Wait: " << x << "s" << endl;
		x--;
		Sleep(1000);
	}
}
int stake_correct_input() {
	string x;
	cout << endl;
	cout << "Enter credit to start round: ";
	cin >> x;
	cout << endl;

	if (x.length() == 0)
		return stake_correct_input();
	for (int i = 0; i < (int)x.length(); i++) {
		if (!isdigit(x[i]))
		{
			cout << "You entered an input error '" << x << "' try again" << endl;
			return stake_correct_input();
		}
	}
	if (x.length() > 13) {
		cout << "Too big amount, please re-enter " << endl;// na prevelikom unosu -858993460 = 0xCCCCCCCC pristupam neinicijaliziranoj memoriji
		return stake_correct_input();
	}

	
	
	int value = stoi(x);
	return value;
}
