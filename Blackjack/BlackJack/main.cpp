#include "game.hpp"
#include <iostream>
#include "other_functions.hpp"
#include <string>
#include <Windows.h>

using namespace std;


int main() {
	game g;
	cout << endl;
here:
	while (1) {

		if (g.play() == false) {
			cout << endl;
			game_header();
			cout << endl;
			cout << endl;
			system("cls");
			break;
		}
	}
	time(3);
	cout << "Za ponovo pokretanje stisni ENTER, za izlazak SPACE+ENTER"; 
	string s;
	getline(cin, s);
	if (cin.get() == '\n')
	{
		system("cls");
		goto here;
	}
	g.game_over();
}
