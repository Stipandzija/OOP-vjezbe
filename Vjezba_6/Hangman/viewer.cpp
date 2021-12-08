#include "viewer.h"
#include <iostream>

using namespace std;

namespace Hangman {
	void Viewer::display_current_progress() {
		int counter = 0;
		int lenght = 0;
		int br = 0;
		for (auto& c : movie) {
			if (c != '_' && !isspace(c) && !ispunct(c)) ++lenght;
		}
		for (const auto& c : guess_movie) {
			if (c != '_' && !isspace(c) && !ispunct(c)) {
				++counter;
				++br;
			}
		}
		lenght = lenght - br;
		cout << counter << " solved " << lenght << " words to quess / " << lives << " lives left\n";
	}
	void Viewer::display_used_letters() {
		for(auto c : guess_movie) cout << c << " ";
		cout << "\n";
	}
	void Viewer::display_hangman() {
		cout << " _______\n";
		cout << "| /   " << (lives < 8 ? "| \n" : "  \n");
		cout << "|/    " << (lives < 7 ? "o \n" : "  \n");
		cout << "|    " << (lives < 6 ?  "/" : " ") << (lives < 5 ? "|" : " ") << (lives < 4 ? "\\ \n" : " \n");
		cout << "|     " << (lives < 3 ? "| \n" : "  \n");
		cout << "|    " << (lives < 2 ? "/ " : "  ") << (lives < 1 ? "\\ \n" : "  \n");
	}
}
