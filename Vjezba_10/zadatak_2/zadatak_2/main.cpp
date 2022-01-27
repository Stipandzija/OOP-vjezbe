#include <iostream>
#include <vector>
#include "Stack.hpp"

using namespace std;

int main() {

	stack<int> v;
	stack<int> v_pun;

	for (int i = 0; i <= 10; i++) {
		v.push(i);
	}
	
	cout << "Pop: " << v.pop() << endl;
	cout <<"************************************* "<< endl;

	for (int i = 0; i < 12; i++) {
		v_pun.push(i);
	}
	cout << "Pop: " << v_pun.pop() << endl;


}