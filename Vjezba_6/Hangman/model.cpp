#include "model.h"
#include <fstream> 
#include <vector> 
using namespace std;


	
Model::Model() : lives(8) {
	ifstream ifs("c:\\temp\\Movie.txt");
	vector<string> movies;
	bool good = ifs.good();
	while (good) {
		string s;
		getline(ifs, s);
		if (!s.empty())
			movies.emplace_back(s);
		good = ifs.good();
	}

	if (!movies.empty()) {
		srand((unsigned)time(0));
		movie = movies[(rand() % movies.size())];
		guess_movie.resize(movie.size());
		for (int i = 0, sz = movie.size(); i < sz; ++i) {
			auto& x = movie[i];
			guess_movie[i] = (isspace(x) || ispunct(x) ? x : '_');
		}
	}
}

bool Model::in_game() {
	return guess_movie.find('_') != string::npos;
}