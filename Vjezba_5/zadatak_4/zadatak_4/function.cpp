#include <iostream>
#include <time.h> 
#include "Header.hpp"

using namespace std;
#define PI 3.14

Meta::Meta(double x1, double y1, double x2, double y2)
{
	x1 = rand() % 50 - 15;
	y1 = rand() % 50 - 15;
	x2 = rand() % 50 - 15;
	y2 = rand() % 50 - 15;
	setMeta(x1, y1, x2, y2);
}
void Meta::setMeta(const double x1, const double y1, const double x2, const double y2)
{
	this->x1 = x1, this->y1 = y1;
	this->x2 = x2, this->y2 = y2;
}

void Weapon::set_point()
{
	this->x = rand() % 50;
	this->y = rand() % 50;
	
}
Weapon::Weapon(int x) { 
	setBullets(x); 
	set_point();
}
void Weapon::setBullets(const int x)
{
	this->number_of_bullet = x;
}

int Weapon::rotate(Meta& m)
{
	int x = this->x, y = this->y;
	int count = 1, n = unsigned(rand() % 10);
	if (this->number_of_bullet < n)
		return 0;
	this->number_of_bullet -= n;

	if (x > m.x1 and x <= m.x2 and y >= m.y1 and y <= m.y2)
		count++;
	if (x > m.x2 and x <= m.x1 and y >= m.y2 and y <= m.y1)
		count++;
	double angle = rand() % 361;
	double radians = angle * (PI / 180.0f);
	this->x = x * cos(radians) - y * sin(radians);
	this->y = x * sin(radians) + y * cos(radians);

	return count;
}
