#include "Header.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include<ctype.h>
#include <cctype>
#include <vector>

using namespace std;
void Unos_Rsheme(vector<string>& R, vector<vector<string>>& F_min) {
	string s;
	string s2;
	vector<string> v;
	cout << "Unesi string: ";
	cin >> s;
	for (auto e : s) {
		if (!ispunct(e))
			;
		else
		{
			cout << "greska u unosu" << endl;
			return;
		}
	}
	R.push_back(s);
	cout << "Koliko f-ovisnosti imate: "; int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Unesi F-ovisnost: ";
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
bool funk(vector<string> v, string s) {
	int i = 0;
	for (string e : v) {
	if (e == s)
			i++;
	}
	if (i == 1)
		return true;
	else
		return false;
}
vector<string> kanonski(vector<vector<string>>& F_min, int odabir, vector<string> &sss) {
	vector<string> v = F_min[odabir - 1];
	vector<string> prazan;
	vector<string> vec = kljucevi_valjda(v);

	for (string s : v) {
		bool x = true;
		bool y = true;
		string lijeva_strana;
		string desni_char;
		string kurac;
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
				kurac.push_back(s[i]);
				int broj = i;
				broj++;
				if(broj<s.size())
					kurac.push_back(s.at(broj));
				if (funk(vec, kurac) == true) {
						zasebni_kanonski.append(lijeva_strana + "->" + kurac);
						prazan.push_back(zasebni_kanonski);
						kurac.clear();
						desni_char.clear();
						zasebni_kanonski.clear();
						i++;
				}
				else {
					zasebni_kanonski.append(lijeva_strana + "->" + desni_char);
					prazan.push_back(zasebni_kanonski);
					desni_char.clear();
					zasebni_kanonski.clear();
					kurac.clear();
				}
			}
			
		
		}
	
		
	}
	cout << "F_min: ";
	for (auto i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	sss = v;
	v.clear();
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

	cout << "R od F je: " << R;
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
	sort(vracam.begin(), vracam.end(), [](const string& l, const string& r) { return l.size() < r.size(); });
	vracam.erase(unique(vracam.begin(), vracam.end()), vracam.end());
	cout << "Lijeva strana: ";
	for (auto i = 0; i < vracam.size(); i++) {
		cout << vracam[i] << " ";
	}
	cout << endl;
	return vracam;
}
void get_substrings_auxx(vector<string>& subs, vector<string> str, unsigned int cnt){

	if (cnt == str.size())
		return;

	int n = subs.size();
	string c = str[cnt];
	for (int i = 0; i < n; ++i) {
		subs.push_back(subs[i] + c);
	}
	get_substrings_auxx(subs, str, ++cnt);
}
void get_substrings_aux(vector<string>& subs, string str, unsigned int cnt) {

	if (cnt == str.size())
		return;

	int n = subs.size();
	char c = str[cnt];
	for (int i = 0; i < n; ++i) {
		subs.push_back(subs[i] + c);
	}
	get_substrings_aux(subs, str, ++cnt);
}

vector<string> kandidati(vector<string> str, string s) {
	vector<string> subs(1);
	vector<string> sub(1);
	int cnt = 0;
	get_substrings_aux(subs, s, cnt);
	subs.erase(subs.begin());
	get_substrings_auxx(sub, str, cnt);
	sub.erase(sub.begin());
	for (string e : sub) {
		subs.emplace_back(e);
	}
	return subs;
}


void tokenize(const string& s, const char* po_kome_dijelim, vector<string>& out) {
	string::size_type beg = 0;

	for (auto end = 0; (end = s.find(po_kome_dijelim, end)) != string::npos; ++end)
	{
		out.push_back(s.substr(beg, end - beg));

		beg = end + strlen(po_kome_dijelim);
	}
	out.push_back(s.substr(beg));
}
string makni_duple(string we) {
	string st = "";
	for (int i = 0; i < we.length(); i++) {
		if (st.find(we[i]) == string::npos) {
			st.push_back(we[i]);
		}
	}
	
	return st;
}
bool petlja(vector<string> svi_lijevi, vector<string> svi_desni, string& e) {
	
	string we = e;
	for (int j = 0; j < svi_lijevi.size(); j++) {
		string z;
		for (int i = 0; i < svi_lijevi[j].length(); i++) {
			if (we.find(svi_lijevi[j][i]) != string::npos) {
				z.push_back(svi_lijevi[j][i]);
			}
			for (int k = 0; k < svi_lijevi.size(); k++) {
				if (z == svi_lijevi[k]) {
					we.append(svi_desni[k]);
				}
			}
		}
		z.clear();
	}
	if (we.length() != e.length()) {
		e.clear();
		e.append(we);
		we.clear();
		return true;
	}
	else 
		return false;
}
bool rekurzivnaa(string s, vector<string> lijeva_s, vector<string> desna_s, string& r, vector<string> F_min, string R_shema) {
	string we = s;
	vector<string> svi_desni;
	vector<string> svi_lijevi;
	for (int i = 0; i < F_min.size(); i++) {
		vector<string> split;
		tokenize(F_min[i], "->", split);
		svi_lijevi.emplace_back(split[0]);
		svi_desni.emplace_back(split[1]);

	}
	
	int brj = 0;
	while (petlja(svi_lijevi, svi_desni, we)) {
		if (brj > 10)
			break;
		brj++;
		;
	}
	sort(we.begin(), we.end());
	we = makni_duple(we);
	if (we == R_shema) {
		r.append(we);
		return true;
	}
	else return false;
}


void rjesenja(vector<string> kandidat, vector<string> lijeva_s, vector<string> desna_s, vector<string> F_min,string R_shema) {
	
	
	string rjesenja_p_kljuci;
	vector<string> lijeva_ss;
	vector<string> desna_ss;// rjesenja od 8 znakova sva
	for (int i = 0; i < kandidat.size(); i++) {
		if (rekurzivnaa(kandidat[i], lijeva_s,desna_s, rjesenja_p_kljuci,F_min,R_shema) == true){
			desna_ss.emplace_back(rjesenja_p_kljuci);
			lijeva_ss.emplace_back(kandidat[i]);
			rjesenja_p_kljuci.clear();
		}		
	}
	for (int i = 0,j=0; i < desna_ss.size(); i++) {
		sort(desna_ss[i].begin(), desna_ss[i].end());
		if(desna_ss[i].length()==R_shema.length() && R_shema==desna_ss[i])
			cout << "Primanri kljuc: " << lijeva_ss[i] << "-" << desna_ss[i] << endl;
	}
	desna_ss.erase(std::unique(desna_ss.begin(), desna_ss.end()), desna_ss.end());
	cout << "Uzimamo: " << desna_ss[0] << endl;
	cout << endl;
}
