#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include "Header.hpp"

using namespace std;

void razdvaja(vector<char>& v)
{
	string s{ "Ja bih, ako ikako mogu, ovu recenicu napisala ispravno." };
	int x = s.length();
	string ss;
	for (int i = 0, j = 1; i < x; i++, j++)
	{
		if ((s.at(i) == ' ') && (s.at(j) == ',')) {
			v.push_back(s.at(j));
			v.push_back(s.at(i));
		}
		v.push_back(s.at(i));
	}
}
void ispisuje(vector<char>& v)
{
	for (char element : v)
		cout << element;
}