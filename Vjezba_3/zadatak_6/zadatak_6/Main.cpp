#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include "Header.hpp"
using std::vector;
using std::string;

using namespace std;


int main() 
{
	vector <string> s;

	input(s);
	reverse(s);
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++) 
	{
		cout << s[i] << endl;
	}
}