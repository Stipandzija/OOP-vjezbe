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
	for(auto i = 0; i < kapacitet; ++i)
	{
		cout<<("Unesi element: ")<<endl;
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
vector<int> erase(vector<int>& v)
{
	cout << "ako zelitre prestat brisat pritisnite Ctrl + z" << endl;
	cout << "Izebrisite element na mjestu n:"<< endl;
	cout << "Unesi n: " << endl;
	int n;
	while(cin>>n){
		v.erase(v.begin() + n);
	}
	return v;
}
