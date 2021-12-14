class Point {
	double x;
	double y;
	double z;

	public:
		Point(double = 0,double = 0,double = 0);
		void setPoint(double min, double max);
		static double find_distance2D(const Point p,const Point p2);
		static double find_distance3D(const Point p, const Point p2);
		void printPoint();

};
