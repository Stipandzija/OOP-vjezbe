#include <iostream>
#include "Game.hpp"
#include "ComputerPlayer.hpp"
#include "HumanPlayer.hpp"
using namespace std;

int main()
{

	japaneza::game g;
	
	g.add_player();
	g.set_bod();

	do
	{
		g.quess_sum();
	} while (!(g.if_game_over()));

}
