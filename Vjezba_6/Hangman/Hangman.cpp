#include <iostream>
#include "viewer.h"

using namespace std;

int main()
{
	Hangman::Viewer hangman;
	while (!hangman.check_game_over()) {
		hangman.display_used_letters();
		hangman.update_lives();
		hangman.display_hangman();
		hangman.display_current_progress();
	}
	cout << "Game over\n";
}
