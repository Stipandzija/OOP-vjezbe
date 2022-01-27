#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Header.hpp"
using namespace std;

void odbaci(vector<int>& v) {
	ifstream ifs("Text.txt");
	try {
		if (!ifs.is_open())
			throw false;

		istream_iterator<int> it(ifs);
		istream_iterator<int> eos;

		copy(it, eos, back_inserter(v));
	}
	catch (bool) {
		cout << "Nepostoji datoteka" << endl;
	}

}
bool provjerava(int& i) {
	int ukupno = 0;
	return i > 500;
}
void prebroji(vector<int>& v) {
	
	int ukup = count_if(v.begin(), v.end(), provjerava);
	cout << "Ukupan broj brojeva vecih od 500: " << ukup << endl;;
}

void min_max(vector<int>& v) {
	cout << "Najmanji broj u vektoru je: " << *min_element(v.begin(), v.end()) << endl;
	cout << "Najveci broj u vektoru je: " << *max_element(v.begin(), v.end()) << endl;
}

void izbaci(vector<int>& v) {
	v.erase(remove_if(v.begin(), v.end(), [](int n) { return n < 300; }), v.end());
}
void sort(vector<int>& v) {
	sort(v.begin(), v.end(), [](int a, int b) {return a < b;});
}