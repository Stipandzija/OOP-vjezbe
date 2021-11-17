#include <iostream>
#include <time.h> 
#include "Header.hpp"

using namespace std;
int main()
{
	srand((unsigned)time(0));
	Point p1;
	Point p2;

	double x = Point::find_distance2D(p1,p2);
	double y = Point::find_distance3D(p1,p2);
	p1.printPoint();
	p2.printPoint();
	cout << " " << endl;
	cout << x << endl;
	cout << " " << endl;
	cout << y << endl;
}