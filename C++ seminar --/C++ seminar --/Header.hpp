#pragma once
#include <vector>
#include <string>
using namespace std;

void Unos_Rsheme(vector<string>&, vector<vector<string>>&);
void Brisanje(vector<string>&, vector<vector<string>>&);
vector<string> kanonski(vector<vector<string>>&, int);
string vracanje(vector<string>);
vector<string> kljucevi_valjda(vector<string>);
vector<string> pot_kljucevi(vector<string>);
void get_substrings_aux(vector<string>& subs, vector<string> str, unsigned int cnt);
bool funk(vector<string>, string);
