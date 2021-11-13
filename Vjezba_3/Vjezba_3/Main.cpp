#include <iostream>
#include "Header.hpp"
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
using std::vector;

int main()
{
	/*int n;
	cout << "Unesi size vektora" << endl;
	cin >> n;
	vector<int> vec;
	input(vec,n);

	
	int x, y;
	cout << "enter the lower limit" << endl;
	cin >> x;
	cout << "enter the upper limit" << endl;
	cin >> y;
	vector <int> vec_tor;
	input2(vec_tor, x, y);
	cout << " " << endl;
	
	vector <int> v1;  
	vector <int> v2;
	input(v1, 5); 
	input(v2, 5);
	vector <int> v3;
	v3 = input3(v1, v2);
	print(v3);
	*/
	vector <int> v;
	input(v, 2);
	/*sort(v.begin(), v.end());
	int s = suma(v);
	cout << "" << endl;
	v.insert(v.begin(), 0);
	v.push_back(s);
	print(v);
	*/
	cout << "" << endl;
	erase(v);
	cout << "" << endl;

}