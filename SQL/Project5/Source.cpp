#include "Header.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <ctype.h>
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
	R.erase(R.begin() + (x - 1));
	F_min.erase(F_min.begin() + (x - 1));
}
/*bool funk(vector<string> v, string s) {
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
*/
vector<string> kanonski(vector<vector<string>>& F_min, int odabir, vector<string> svi_lijevi, vector<string> svi_desni, vector<string>& sss) {
	vector<string> v = F_min[odabir - 1];
	vector<string> prazan;  // nadopuna na kraju koda
	for (int i = 0; i < svi_desni.size(); i++) {
		for (auto el : svi_desni[i]) {
			prazan.push_back(svi_lijevi[i] + "->" + el);
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

string vracanje(vector<string> v, string R_shema) {

	string R;
	for (string s : v) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '-' || (s[i] == '>')) {
				continue;
			}
			else {
				R.push_back(s[i]);
			}
		}
	}
	string r;
	for (auto e : R_shema) {
		if (R.find(e) != string::npos) {
			r.push_back(e);
		}
	}
	cout << "R od F je: " << r;
	cout << endl;
	return R;
}
/*
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
*/
void get_substrings_auxx(vector<string>& subs, vector<string> str, unsigned int cnt) {

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

vector<string> kandidati(vector<string> str, string s /*R_shema*/) {
	vector<string> subs(1);
	vector<string> sub(1);
	int cnt = 0;
	get_substrings_aux(subs, s, cnt);
	subs.erase(subs.begin());
	get_substrings_auxx(sub, str, cnt);
	sub.erase(sub.begin());
	for (string e : sub) {
		subs.push_back(e);
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

bool rekurzivnaa(string s, vector<string> svi_lijevi, vector<string> svi_desni, string& r, string R_shema) {
	string we = s;
	string sg;
	s.clear();
	int brj = 0;
	while (petlja(svi_lijevi, svi_desni, we)) {
		if(1){
			string provjera = R_shema;
			string provjera2 = we;
			
			int broj = 0;
			for (auto e : provjera) {
				if (provjera2.empty())
					break;
				int index = provjera2.find(e);
				if ((index != std::string::npos)){
					sg+=e;
					provjera2.erase(provjera2.begin() + index);
					broj++;
				}
			}
			if (broj == provjera.length()) {
				r.append(sg);
				we.clear();
				return true;
			}
			broj = 0;
			
		}
		if (brj > 10) // koliko ce se puta petljan ponovit dok ne nade rjesenje
			break;
		brj++;
		;
		sg.clear();
	}
	
	return false;

}

string rjesenja(vector<string> kandidat, vector<string> lijeva_s, vector<string> desna_s, vector<string> F_min, string R_shema) {


	string rjesenja_p_kljuci;
	vector<string> lijeva_ss;
	vector<string> desna_ss;// rjesenja od 8 znakova sva
	for (int i = 0; i < kandidat.size(); i++) {
		if (rekurzivnaa(kandidat[i], lijeva_s, desna_s, rjesenja_p_kljuci, R_shema) == true) {
			desna_ss.push_back(rjesenja_p_kljuci);
			lijeva_ss.push_back(kandidat[i]);
			rjesenja_p_kljuci.clear();
		}
	}
	
	vector<string> vec;
	for (int i = 0, j = 0; i < desna_ss.size(); i++) {
		if (desna_ss[i].length() == R_shema.length() && R_shema == desna_ss[i]) {
			vec.push_back(lijeva_ss[i]);
		}
		else {
			cout << "Nema kljuceva" << endl;
			break;
		}
	}
	
	vector<string> rj;
	for (auto e : vec) { // sortiram string abecedno i pusham u vektor da bi izbacio moguce duplikate
		sort(e.begin(), e.end());
		rj.push_back(e);
	}
	vec.clear();
	
	sort(rj.begin(), rj.end());
	auto last = unique(rj.begin(), rj.end()); // izbrisi sve duplikate, ako je redosljed slova jednak
	rj.erase(last, rj.end());
	
	sort(rj.begin(), rj.end(), [](const string& l, const string& r) { return l.size() < r.size(); });
	for (int i = 0; i < rj.size(); i++) {
		cout << "Primanri kljuc: " << rj[i] << "-" << desna_ss[i] << endl;
	}
	cout << "Uzimamo: " << rj[0];
	cout << endl;

	return rj[0];
}


void treca_norm(string prime_key, vector<string> svi_lijevi, vector<string> svi_desni, string R_shema) {
	vector<string> R;
	vector<string> sve;

	for (int i = 0; i < svi_lijevi.size(); i++) {
		string str;
		sve.emplace_back(str.append(svi_lijevi[i] + svi_desni[i]));

	}
	sort(prime_key.begin(), prime_key.end());

	for (int i = 0; i < sve.size(); i++) {
		for (int j = 1; j < sve.size(); j++) {
			if (sve[j].find(sve[i]) != string::npos) {
				if (sve[j] == sve[i])
					continue;
				if (sve[i].length() <= sve[j].length())
					sve.erase(sve.begin() + i);
				else
					sve.erase(sve.begin() + j);

			}
		}
	}
	bool t = true;

	for (int i = 0; i < sve.size(); i++) {
		if (sve[i].find(prime_key) == string::npos) {
			t = false;
		}
	}

	if (t == false) {
		sve.emplace_back(prime_key);
	}
	for (int i = 0; i < sve.size(); i++) {
		cout << "R" << i << "(" << sve[i] << ")" << endl;
	}
}

