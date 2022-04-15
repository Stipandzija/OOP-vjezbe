#include "Header.hpp"
#include <algorithm>
#include <iostream>
using namespace std;
void Unos_Rsheme(vector<string>& R, vector<vector<string>>& F_min) {
	string s;
	string s2;
	vector<string> v;
	cout << "Unesi string: ";
	cin >> s;
	R.push_back(s);
	for (int i = 0; i < 5; i++) {
		cout << "Unesi F-ovisnost";
		cin >> s2;
		v.push_back(s2);
	}
	F_min.push_back(v);
}
void Brisanje(vector<string>& R, vector<vector<string>>& F_min) {
	cout << "KOji broj zelis obrisat";
	int x; cin >> x;
	R.erase(R.begin() + (x-1));
	F_min.erase(F_min.begin() + (x-1));
}
vector<string> kanonski(vector<vector<string>>& F_min, int odabir) {
	vector<string> v = F_min[odabir - 1];
	vector<string> prazan;

	
	for (string s : v) {
		bool x = true;
		string q;
		for (int i = 0; i < s.size(); i++) {
			if (s[i]=='-' || (s[i] == '>')) {
				if (s[i] == '>')
					x = false;
				continue;
			}
			else if (x==false)
			{
				q.push_back(s[i]);
			}
			
		}

	}

}