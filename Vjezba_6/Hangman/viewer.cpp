#include "model.h"
#include <iostream>

using namespace std;

void Viewer::display_current_progress(Model& m) {
	int counter = 0;
	int lenght = 0;
	int br = 0;
	for (auto& c : m.movie) {
		if (c != '_' && !isspace(c) && !ispunct(c)) ++lenght;
	}
	for (const auto& c : m.guess_movie) {
		if (c != '_' && !isspace(c) && !ispunct(c)) {
			++counter;
			++br;
		}
	}
	lenght = lenght - br;
	cout << counter << " solved " << lenght << " words to quess / " << m.lives << " lives left\n";
}
void Viewer::display_used_letters(Model& m) {
	for (auto c : m.guess_movie) cout << c << " ";
	cout << "\n";
}
void Viewer::display_hangman(Model& m) {
	cout << " _______\n";
	cout << "| /   " << (m.lives < 8 ? "| \n" : "  \n");
	cout << "|/    " << (m.lives < 7 ? "o \n" : "  \n");
	cout << "|    " << (m.lives < 6 ? "/" : " ") << (m.lives < 5 ? "|" : " ") << (m.lives < 4 ? "\\ \n" : " \n");
	cout << "|     " << (m.lives < 3 ? "| \n" : "  \n");
	cout << "|    " << (m.lives < 2 ? "/ " : "  ") << (m.lives < 1 ? "\\ \n" : "  \n");
}
