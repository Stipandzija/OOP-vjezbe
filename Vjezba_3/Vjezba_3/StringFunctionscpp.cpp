#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <iterator>
#include "Header.hpp"

using namespace std;
using std::string;
size_t count_s(const string& s, const string& s2)
{
	int count = 0;
	int x = s.find(s2, 0);
	while (x != string::npos)
	{
		count++;
		x = s.find(s2, x + 1);
	}
	return count;
}
vector<int> input(vector<int>& arr)
{
	cout << "Unosi stringove dok ne pritisnec Ctrl+z" << endl;
	while(cin>>a)
	{

	}
}