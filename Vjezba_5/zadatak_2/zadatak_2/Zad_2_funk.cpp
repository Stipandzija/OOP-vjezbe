#include <iostream>
#include <time.h> 
#include "Header.hpp"


using namespace std;

Point::Point(double x, double y, double z)
{
	cout << "Unesi kordinate x,y,z" << endl;
	cin >> x;
	cin >> y;
	cin >> z;
	setPoint(x, y, z);
}
void Point::setPoint(const double x, const double y, const double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Weapon::Weapon(int x, int y)
{
	setBullets(x, y);
}
void Weapon::setBullets(const int x, int y)
{
	this->number_of_bullet = x;
	this->n = y;
}
void Weapon::shoot(int x)
{
		if(this->n <x)
		{
			refill();
		}
		this->n -=x;
		if (this->n == 0)
			refill();
}