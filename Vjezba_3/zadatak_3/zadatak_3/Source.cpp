#include <iostream>
#include "Header.hpp"
#include <vector>
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
int suma(vector<int>& v)
{
	int zbroj = 0;
	for (int j = 0;;) {
		for (auto i = v.begin(); i != v.end(); ++i) {
			zbroj += v.at(j);
			j++;
		}
		break;
	}
	return zbroj;
}