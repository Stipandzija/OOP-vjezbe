class Point
{
	double x;
	double y;

	public:
		Point(double = 0, double = 0);
		void setPoint(const double x, const double y);
		friend class Meta;
};
class Meta
{
	public:
		int condition(Point& t1, Point& t2,Point &p);

};