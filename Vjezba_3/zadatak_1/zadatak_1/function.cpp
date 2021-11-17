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
vector<int> input2(vector<int>& arr, int x, int y)
{
	int a;
	cout << "enter the element" << endl;
	cin >> a;
	while (x < a && a < y)
	{
		arr.push_back(a);
		cout << "enter the element" << endl;
		cin >> a;
	}
	return arr;
}
void print(vector<int>& arr)
{
	for (int j = 0;;) {

		for (auto i = arr.begin(); i != arr.end(); ++i)
		{
			cout << arr.at(j) << endl;
			j++;
		}
		cout << endl;
		break;
	}
}