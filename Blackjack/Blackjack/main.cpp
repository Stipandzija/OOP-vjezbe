#include "game.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>

using namespace std;


	int main() {
		srand(time(NULL));
		game g;
		g.game_start();
		cout << endl;

	here:
		while (1) {

			if (g.play() == false) {
				cout << endl;
				g.game_over();
				cout << endl;
				cout << endl;
				break;
			}
		}
		int x = 3;
		while (x) {
			x--;
			cout << "Ponovno pokretanje za " << x << " sekudni" << endl;
			Sleep(1000);
		}
		cout << "Za ponovno pokretanje stisnite dva puta ENTER"; string s;
		getline(cin, s);
		if (cin.get() == '\n')
			goto here;



	}
