#include <iostream>
#include <time.h> 
#include <cmath> 
#include "Header.hpp"

using namespace std;

Point::Point(double x,double y,double z)
{
    setPoint(0, 15);
}

void Point::setPoint(double min, double max)
{
    this->x =  (min + 1) + (((float)rand()) / (float)RAND_MAX) * (max - (min + 1));
    this->y = (min + 1) + (((float)rand()) / (float)RAND_MAX) * (max - (min + 1));
    this->z = (min + 1) + (((float)rand()) / (float)RAND_MAX) * (max - (min + 1));

}

double Point::find_distance2D(const Point p,const Point p2)
{   
    double distancex = pow(p2.x - p.x,2);
    double distancey = pow(p2.y - p.y, 2);

    double distance = sqrt(distancex + distancey);
    return distance;
}
double Point::find_distance3D(const Point p, const Point p2)
{
    double distancex = pow(p2.x - p.x, 2);
    double distancey = pow(p2.y - p.y, 2);
    double distancez = pow(p2.z - p.z, 2);

    double distance = sqrt(distancex + distancey + distancez);
    return distance;
}

void Point::printPoint()
{
    
     cout << "(" << x << "," << y << "," << z << ")";
    
}

