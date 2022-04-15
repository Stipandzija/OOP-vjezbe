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
		else if (odabir>0 && odabir <=10) {
			vector<string> v=kanonski(F_min,odabir);
		}
		else if (odabir != R_shema.size()) { izvrsavanje = false; }




		izvrsavanje = false;//izlazi iz petlje program gotov
	}
}