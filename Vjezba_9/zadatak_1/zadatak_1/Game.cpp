#include <iostream>
#include "HumanPlayer.hpp"
#include "Player.hpp"
#include "ComputerPlayer.hpp"
#include "Game.hpp"
#include <vector>
#include <time.h>

using namespace std;

namespace japaneza{
	void game::add_player()
	{
		for (int i = 0; i < 1; i++)
		{
			human_player* h = new human_player;
			hp.push_back(*h);
		}
	}
	void game::set_bod()
	{
		player p;
		dog_br_bodova = p.get_bod();
	}
	bool game::if_game_over()
	{
		int i = 1;
		for(auto& el: hp)
		{
			if(el.get_points()==dog_br_bodova)
			{
				cout << i << ". igrac je pobjedio" << endl;
				return true;
			}
			i++;
		}
		if(cp.get_points()==dog_br_bodova)
		{
			cout << "Computer won" << endl;
			return true;
		}
		return false;
		
	}
	bool game::random_sum(int x, int y)
	{
		srand(time(NULL));
		vector<int> v;
		v.push_back(1), v.push_back(2), v.push_back(5);
		int sum = 0, broj_kov = x;
		while (broj_kov != 0) {
			sum += v[(0 + rand() % v.size())];
			broj_kov--;
		}
		if (sum == y)
			return true;
	}

	void game::quess_sum()
	{
		for(auto& el:hp)
		{
			cout << "Koliko zelis kovanica: ";
			int x; cin >> x;
			if ((x > 3) || (x == 0))
			{
				cout << "Pogresana unos" << endl;
				quess_sum();
			}
			cout << "Pogodi sumu: ";
			int y; cin >> y;
			if (random_sum(x, y) == true)
				el.set_up_points();
		}
		for(int i=0;i<1;i++)
		{
			//broj kovanica
			int x;
			x = (0 + rand() % 3);
			int y = (0 + rand() % 15);
			if (random_sum(x, y) == true)
				cp.set_up_points();
		}
	}
	
}