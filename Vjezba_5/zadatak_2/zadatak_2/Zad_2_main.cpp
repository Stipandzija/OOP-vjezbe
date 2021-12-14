#include <iostream>
#include <time.h> 
#include "Header.hpp"


using namespace std;

int main()
{
	Weapon w(30, 15);
	int x;
	cout << "Koliko zelis metaka ispucati, ako zelis stati Ctrl+Z" << endl;
	while(cin>>x)
	{
		w.shoot(x);
	}
}