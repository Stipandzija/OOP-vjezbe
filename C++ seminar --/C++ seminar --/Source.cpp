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
		bool y = true;
		string lijeva_strana;
		string desni_char;
		string zasebni_kanonski;
		for (int i = 0; i < s.size(); i++) {
			
			if (s[i] == '-' || (s[i] == '>')) {
				if (s[i] == '-')
					y = false;
				else if (s[i] == '>')
					x = false;
				continue;
			}
			else if (y == true) {
				lijeva_strana.push_back(s[i]);
			}
			else if (x == false)
			{
				desni_char.push_back(s[i]);
				zasebni_kanonski.append(lijeva_strana + "->" + desni_char);
				prazan.push_back(zasebni_kanonski);
				desni_char.clear();
				zasebni_kanonski.clear();
			}
			
		
		}
	
		
	}
	cout << "F_min: ";
	for (auto i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "F_min u kanonskom obliku: ";
	for (auto i = 0; i < prazan.size(); i++) {
		cout << prazan[i] << " ";
	}
	cout << endl;
	return prazan;
}
string vracanje(vector<string> v) {

	string R;
	for (string s : v) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '-' || (s[i] == '>')) {
				continue;
			}
			else {
				size_t pos = R.find(s[i]);
				if (pos == std::string::npos)
					R.push_back(s[i]);
			}
		}
	}

	cout <<"R od F je: " << R;
	cout << endl;
	return R;
}
vector<string> kljucevi_valjda(vector<string> v) {
	vector<string> vracam;
	for (string e : v) {
		string s;
		size_t pos = e.find('-');
		if (pos != std::string::npos)
		{
			vracam.push_back(e.substr(0, pos));
		}
	}
	sort(vracam.begin(), vracam.end());
	vracam.erase(unique(vracam.begin(), vracam.end()), vracam.end());
	cout << "Lijeva strana: ";
	for (auto i = 0; i < vracam.size(); i++) {
		cout << vracam[i] << " ";
	}
	cout << endl;
	return vracam;
}