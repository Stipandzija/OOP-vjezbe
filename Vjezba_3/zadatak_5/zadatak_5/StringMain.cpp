#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <iterator>
#include "Header.hpp"

using namespace std;
using std::string;

int main()
{
	string s;
	string s2;

	cout << "Unesi prvi string" << endl;
	cin >> s;
	cout << "Unesi drugi string" << endl;
	cin >> s2;

	int x = count_s(s, s2);
	cout << x << endl;
}