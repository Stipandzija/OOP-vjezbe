class Meta
{
	double x1;
	double y1;
	double x2;
	double y2;

public:
	Meta(double = 0, double = 0, double = 0, double = 0);
	void setMeta(const double x1, const double y1, const double x2, const double y2);
	friend class Weapon;
};
class Weapon 
{
	int number_of_bullet;
	double x, y;
public:
	Weapon(int = 10000);
	void set_point();
	void setBullets(const int number_of_bullets);
	int rotate(Meta &m);
};
