#include <iostream>
#include <stdbool.h>
#include "Header.hpp"

using namespace std;

Point::Point(double x, double y)
{
	cout << "Unesi kordinate x,y" << endl;
	cin >> x;
	cin >> y;
	setPoint(x, y);
}
void Point::setPoint(const double x, const double y)
{
	this->x = x;
	this->y = y;
}

int Meta::condition(Point& t1, Point& t2,Point &p)
{
	if (p.x >= t1.x and p.x <= t2.x and p.y >= t1.y and p.y <= t2.y)
		return true;
	if (p.x >= t2.x and p.x <= t1.x and p.y >= t2.y and p.y <= t1.y)
		return true;

	return false;
}