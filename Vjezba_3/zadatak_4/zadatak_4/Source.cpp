#include <iostream>
#include "Header.hpp"
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
using std::vector;

vector<int> input(vector<int>& arr, int n)
{
	int value;
	int kapacitet = (n * 2);
	for (auto i = 0; i < kapacitet; ++i)
	{
		cout << ("Unesi element: ") << endl;
		cin >> value;
		arr.push_back(value);
	}
	return arr;
}
vector<int> erase(vector<int>& v)
{
	cout << "ako zelitre prestat brisat pritisnite Ctrl + z" << endl;
	cout << "Izebrisite element na mjestu n:" << endl;
	cout << "Unesi n: " << endl;
	int n;
	while (cin >> n) {
		v.erase(v.begin() + n);
	}
	return v;
}