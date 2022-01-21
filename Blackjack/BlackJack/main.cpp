#include "game.hpp"
#include <iostream>
#include "other_functions.hpp"
#include <string>
#include <Windows.h>

using namespace std;


int main() {
	game g;
	cout << endl;
	bool b = false;
	 do{
		do{

			if (g.play() == false) {
				cout << endl;
				game_header();
				cout << endl;
				cout << endl;
				system("cls");
				break;
			}
		} while (1);
		time(3);
		cout << "Za ponovo pokretanje stisni ENTER, za izlazak SPACE+ENTER";
		string s;
		getline(cin, s);
		if (cin.get() == '\n')
		{
			system("cls");
			b = true;

		}
		else
			b = false;
	 } while (b==true);
	 system("cls");
	g.game_over();
}
