#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "Header.hpp"
using std::vector;
using std::string;

using namespace std;

void input(vector <string>& str)
{
	string s;
	for (int i = 0; i < 5; i++) 
	{
		cout << "Unesi string" << endl;
		cin >> s;
		str.push_back(s);
	}
}
void reverse(vector <string>& str) 
{
	for (int i = 0; i < str.size(); i++) 
	{
		reverse(str[i].begin(), str[i].end());
	}
}