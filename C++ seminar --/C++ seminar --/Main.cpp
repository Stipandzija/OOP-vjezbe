#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include "Header.hpp"
using namespace std;

int main() {

	vector<string> R_shema = { "ABCDEFGHIJ","ABCDEFGHIJK","ABCDEFGHIJKLMNO","ABCDEFGHIJKLMNOP","ABCDEFGHIJKL","ABCDEFGHIJ","ABCDEFGHIJKLMNOPRS","ABCDEFGHIJK","ABCDEFGHIJKLM","ABCDEFGHIJKL" };
	vector<vector<string>> F_min = { {"DI->B" , "AJ->F" , "GB->FJE" , "AJ->HD" , "I->CG"}, {"AB->D","B->E","C->AB", "DF->GHK", "DEI->ABC", "BH->JKA", "I->AK"}
	,{"AB->EF","CD->FGEH","EO->AHIJK", "L->MN", "N->ABCDEF", "KM->GHIAC", "F->MNO"},{"A->A","A->B","B->A","B->B", "CD->ABCDEFGHIJKL", "ME->NOP", "D->M"},
		{"A->BCE","C->EH","DFG->IJKL","L->AB", "B->DEL"},{"A->BCDE","BCD->EFG","CH->I","D->AI", "FA->GHAC"},{"A->BCDE","C->AEFGHIJK","K->LMNAOP", "EF->AOKC", "P->AB", "DE->PC"},
		{"AEI->JAC","DE->IFGHA","FAG->A","EFI->DECAB","F->AIJFB"},{"BM->JKLADE","MD->FKLJ","G->BCDEF","FI->HIJK", "CE->BMDIF"},{"A->B","B->C","C->D","D->E","E->F", "F->G", "G->H", "H->I", "I->J", "J->ABCDEFGHI", "L->J"} };

	bool izvrsavanje = true;
	while (izvrsavanje == true) //program se izvrsava dok je true
	{
		int b;
		for (int i = 0; i < R_shema.size(); i++) {
			cout << i + 1 << ". " << "R= " << R_shema[i] << " , " << "Fmin= ";
			for (int j = 0; j < F_min[i].size(); j++) {
				cout << F_min[i][j] << " ";
			}
			cout << endl;
			b = i;
		}
		cout << b + 2 << "." << " Brisanje relacijske sheme i FO" << endl;
		cout << b + 3 << "." << " Unesi novu relacijsku shemu i FO" << endl;
		cout << b + 4 << "." << " Kraj" << endl;
		
		int odabir; cout << "Unesi broj koi zelis odabrat: "; cin >> odabir;
		if (odabir == (R_shema.size() + 3)) {
			izvrsavanje = false;

			cout << "Kraj programa" << endl;
			continue;
		}
		else if (odabir > (R_shema.size() + 3)) {
			izvrsavanje = false;
			cout << "Greska u unosu" << endl;
			continue;
		}
		else if (odabir == (R_shema.size() + 2)) {
			Unos_Rsheme(R_shema, F_min);
			izvrsavanje = true;
			continue;
		}
		else if (odabir == (R_shema.size() + 1)) {
			Brisanje(R_shema, F_min);
			izvrsavanje = true;
			continue;

		}
		else if (odabir > 0 && odabir <= 10) {
			vector<string> sss;
			vector<string> v = kanonski(F_min, odabir,sss);
			string v2 = vracanje(v);
			vector<string> v3 = kljucevi_valjda(v);
			multimap<string, string> maper;
			
			vector<string> svi_desni;
			vector<string> svi_lijevi;//sve sa ljeve strane bez ponavljanja

			
			for (const auto& val : F_min[odabir - 1]) {// v je zamjenjiv
				vector<string> split;
				tokenize(val, "->", split);
				
					svi_lijevi.push_back(split[0]);
					svi_desni.push_back(split[1]);
				
			}
			cout << endl;
			vector<string> v4 = kandidati(svi_lijevi,R_shema[odabir-1]);
			sort(v4.begin(), v4.end(), [](const string& l, const string& r) { return l.size() < r.size(); });
			v4.erase(unique(v4.begin(), v4.end()), v4.end());

			rjesenja(v4, svi_lijevi, svi_desni,sss, R_shema[odabir - 1]);
			
		}
	}

}
