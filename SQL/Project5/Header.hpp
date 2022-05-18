#pragma once
#include <vector>
#include <string>
using namespace std;

void Unos_Rsheme(vector<string>&, vector<vector<string>>&);
void Brisanje(vector<string>&, vector<vector<string>>&);
vector<string> kanonski(vector<vector<string>>&, int, vector<string>, vector<string>, vector<string>&);
string vracanje(vector<string>, string);
vector<string> kljucevi_valjda(vector<string>);
void get_substrings_aux(vector<string>& subs, string, unsigned int cnt);
void get_substrings_auxx(vector<string>& subs, vector<string>, unsigned int cnt);
bool funk(vector<string>, string);
vector<string> kandidati(vector<string>, string);
string rjesenja(vector<string>, vector<string>, vector<string>, vector<string>, string);
bool find_in_string(string, string);
bool find_in_string(int pos, string s, string str);
bool rekurzivnaa(string, vector<string>, vector<string>, string&, string);
void tokenize(const string&, const char*, vector<string>&);
bool prov(string, string);
bool petlja(vector<string>, vector<string>, string&);
void treca_norm(string, vector<string>,vector<string>,string);