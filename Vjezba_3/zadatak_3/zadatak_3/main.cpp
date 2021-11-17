#include <iostream>
#include "Header.hpp"
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
using std::vector;

int main()
{
	vector <int> v;
	input(v, 2);
	sort(v.begin(), v.end());
	int s = suma(v);
	cout << "" << endl;
	v.insert(v.begin(), 0);
	v.push_back(s);
}