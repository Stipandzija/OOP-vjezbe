#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
template <class T>
void sortiranje(vector<T>& v)
{
	sort(v.begin(), v.end());
}

template<>
void sortiranje(vector<char>& v)
{
	for (int i = 0; i < (int)v.size(); i++)
	{
		char c = v[i];
		if (isupper(v[i])) {
			c = tolower(v[i]);
			v[i] = c;
		}
	}
	sort(v.begin(), v.end());
}