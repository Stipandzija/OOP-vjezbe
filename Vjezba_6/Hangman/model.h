#include <string>
using namespace std;


class Model {
	int lives;
	string movie;
	string guess_movie;
public:
	Model();
	bool in_game();
	friend class Viewer;
	friend class Controller;
};


class Controller {
public:
	char user_entry();
	bool check_letter(Model& m, char c);
	void update_lives(Model& m);
	bool check_game_over(Model& m);

};

class Viewer {
public:
	void display_current_progress(Model& m);
	void display_used_letters(Model& m);
	void display_hangman(Model& m);
};

