#pragma once
#include <iostream>
using namespace std;

namespace japaneza {
	class player
	{
		int dog_broj_bod;
			public:
				void input_bod() {
					int x;
					cout << "Unesi broj bodova" << endl;
					cin >> x;
					dog_broj_bod = x;
				}
				int get_bod() { input_bod(); return dog_broj_bod; }

			
			
	};
}