#include <iostream>
#include "Header.hpp"
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
using std::vector;

int main()
{
	vector <int> v1;
	vector <int> v2;
	input(v1, 5);
	input(v2, 5);
	vector <int> v3;
	v3 = input3(v1, v2);
}