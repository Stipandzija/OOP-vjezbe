#pragma once
#include "controller.h"

using namespace std;

namespace Hangman {
	class Viewer : public Controller {
	public:
		void display_current_progress();
		void display_used_letters();
		void display_hangman();
	};
}
