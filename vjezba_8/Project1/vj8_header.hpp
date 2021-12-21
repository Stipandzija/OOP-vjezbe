#include <iostream>
#include <cstdbool>

using namespace std;


class timer
{
	int h;
	int m;
	double s;
		public:
			timer() { this->h = 0, this->m = 0, this->s = 0; };
			timer(int h, int m, double s) { this->h = h, this->m = m, this->s = s; }
			timer(const timer& t);
			timer(timer&& other);

			timer& operator += (const timer& t) { this->h += t.h, this->m += t.m, this->s += t.s; return *this; }
			timer& operator -= (const timer& t) { this->h -= t.h, this->m -= t.m, this->s -= t.s; return *this; }
			timer& operator /= (const float t) { this->h /= t, this->m /= t, this->s /= t; return *this; }
			timer operator /(const float& t) { return timer(this->h / t, this->m / t, this->s / t); }
			friend ostream& operator << (ostream&, const timer&);
			bool operator < (timer& t);
			timer operator-(timer& t);
			timer operator+(timer& t);
			operator double() { return double((h*3600) + (m*60) + s); }

			int get_value_h() const { return h; }
			int get_value_m() const { return m; }
			double get_value_s() const { return s; }

			void add(const double m);
			~timer() { }

};

class penalty
{
	double m;
public:
	penalty();
	penalty(double m) { this->m = m; }
	void operator()(timer& t) { t.add(m); }
};