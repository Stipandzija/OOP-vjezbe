class Point
{
	double x;
	double y;
	double z;

	public:
		Point(double = 0, double = 0, double = 0);
		void setPoint(const double x, const double y, const double z);
};

class Weapon
{
	Point p;
	int number_of_bullet;
	int n;
	
	public:
		Weapon(int = 0, int = 0);
		void setBullets(const int number_of_bullets,int n);
		void shoot(int x);
		void refill() { this->n = number_of_bullet; };
};
