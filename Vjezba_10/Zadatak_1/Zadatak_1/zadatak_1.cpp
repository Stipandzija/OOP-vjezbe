#include <iostream>
#include <vector>
#include "Header.hpp"

using namespace std;

int main()
{
	vector<int> v1;
	vector<char> v2;
	for (int i = 0; i < 5; i++) {
		cout << "Unesi broj: ";
		int x; cin >> x;
		cout << endl;
		cout << "Unesi char: ";
		char c; cin >> c;
		cout << endl;
		v1.push_back(x);
		v2.push_back(c);
	}

	sortiranje(v1);
	sortiranje<char>(v2);
	for (int i = 0; i < (int)v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < (int)v2.size(); i++) {
		cout << v2[i] << " ";
	}





}