#include "vj8_header.hpp"
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

ostream& operator << (ostream& o, const timer& t)
{
	o << '(' << t.h << ':' << t.m << ':' << t.s << ')';
	return o;
}
bool timer::operator < (timer& t1) { 
	if ((h < t1.h) && (m < t1.m) && (s < t1.s))
		return 1;
	return 0;
}
timer timer::operator-(timer& t)
{
	timer t1;

	t1.h = h - t.h, t1.m = m - t.m, t1.s = s - t.s;
	return t1;
}
timer timer::operator+(timer& t)
{
	timer t1;

	t1.h = h + t.h, t1.m = m + t.m, t1.s = s + t.s;
	return t1;
}
void timer::add(const double m)
{
	this->s += m;
	if (s >= 60)
		this->m += 1;
	if (m >= 60)
		this->h += 1;
}
timer::timer(const timer& t) { h = t.h, m = t.m, s = t.s; }
timer::timer(timer&& other) : h(move(other.h)), m(move(other.m)), s(move(other.s)) {}


