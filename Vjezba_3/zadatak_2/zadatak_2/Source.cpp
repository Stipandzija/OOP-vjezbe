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
vector<int> input3(vector<int>& arr1, vector<int>& arr2)
{
	vector <int> v;
	for (int q = 0;;) {
		for (auto i = arr1.begin(); i != arr1.end(); ++i) {
			int a = 0;
			for (auto j = arr2.begin(); j != arr2.end(); ++j) {

				if (arr1.at(q) != arr2.at(a)) {
					v.push_back(arr1.at(q));
					break;
				}
				a++;
			}
			q++;
		}
		break;
	}
	return v;
}