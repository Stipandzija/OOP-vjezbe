using namespace std;

class Board
{
	char** board;
	double row;
	double coll;
	char ch;

		public:
			friend struct Point;
			Board(double r, double c, char ch) { this->row = r, this->coll = c, this->ch = ch; }
			void Matrix();
			void draw_char(const struct Point&, char chh);
			void draw_up_line(const struct Point&, char chh);
			void draw_line(const struct Point&, const struct Point&, char chh);

			Board() { this->row = 10; this->coll = 20; }
			Board(Board& b);
			Board(Board&& b);
			~Board();
			void print();

};
struct Point
{
	double x;
	double y;

	static Point point(Board& b,int q);
};


