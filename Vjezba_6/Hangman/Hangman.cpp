#include <iostream>
#include "model.h"

using namespace std;

int main()
{
	Viewer hangman;
	Model model;
	Controller con;
	while (!con.check_game_over(model)) {
		hangman.display_used_letters(model);
		con.update_lives(model);
		hangman.display_hangman(model);
		hangman.display_current_progress(model);
	}
	cout << "Game over\n";
}
