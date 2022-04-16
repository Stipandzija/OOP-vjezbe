#include <iostream>
#include <vector>
#include <string>
#include "Header.hpp"
using namespace std;

int main() {

	vector<string> R_shema = { "ABCDEFGHIJ","ABCDEFGHIJK","ABCDEFGHIJKLMNO","ABCDEFGHIJKLMNOP","ABCDEFGHIJKL","ABCDEFGHIJ","ABCDEFGHIJKLMNOPRS","ABCDEFGHIJK","ABCDEFGHIJKLM","ABCDEFGHIJKL" };
	vector<vector<string>> F_min = { {"A->B", "A->C", "B->CD", "G->ABC", "HI->DEFJ", "J->AB", "F->GHI"}, {"AB->D","B->E","C->AB", "DF->GHK", "DEI->ABC", "BH->JKA", "I->AK"}
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

		int R_size = R_shema.size();
		int odabir; cout << "Unesi broj koi zelis odabrat: "; cin >> odabir;
		if (odabir == 13) {
			izvrsavanje = false;

			cout << "Kraj programa" << endl;
			continue;
		}
		else if (odabir > 13) {
			izvrsavanje = false;
			cout << "Greska u unosu" << endl;
			continue;
		}
		else if (odabir == 12) {
			Unos_Rsheme(R_shema,F_min);
		}
		else if (odabir == 11) {
			Brisanje(R_shema, F_min);

		}
		else if(odabir>0 && odabir <=10) {
			vector<string> v=kanonski(F_min,odabir);
			string v2=vracanje(v);
			vector<string> v3 = kljucevi_valjda(v);
			vector<string> v4 = pot_kljucevi(v3);
			

// triba napisat funkciju koja iz v4 (to su kandidati) izvlaci sve moguce primarne kljuceve preko zadanih funkcionalnih ovisnosti(FO u kodu)
		}
		izvrsavanje = false;//izlazi iz petlje program gotov
	}
}