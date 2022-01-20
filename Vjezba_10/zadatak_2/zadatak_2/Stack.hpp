#ifndef STACK__HPP_
#define STACK__HPP_
#include <vector>
#include <iostream>

using namespace std;

template<typename X>
class stack {

	X* v;
	int t;

public:
	stack();
	void push(X v);
	X pop();
	bool is_empty();
	virtual ~stack();
};

template<typename X>
stack<X>::stack() {
	this->v = new X[10];
	t = -1;
}

template<typename X>
stack<X>::~stack() {
	delete[] v;
}

template<typename X>
void stack<X>::push(X number) {
	if (!(t == 10 - 1))
		v[++t] = number;
	else
		cout << "Pun" << endl;
}
template<typename X>
bool stack<X>::is_empty() {
	if (t == -1)
		return true;
	return false;
}
template <typename X>
X stack<X>::pop()
{
	if (!is_empty())
		return v[t--];
	else
		cout << "Prazan" << endl;
}



#endif