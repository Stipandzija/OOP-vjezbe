#include <iostream>
#include "Board.hpp"

using namespace std;

/*U zadataku su x i y obrnuti nego u primjeru sa moodla npr. (16,8) - > (8,16)*/

int main()
{
	cout << "Unesite znak za okvir Board: ";
	char ch;
	cin >> ch;
	int r_broj = 1;
	Board b(10, 20, ch);
	b.Matrix();
	Point p1 = Point::point(b,r_broj);
	Point p2 = Point::point(b, ++r_broj);
	Point p3 = Point::point(b, ++r_broj);
	Point p4 = Point::point(b, ++r_broj);

	cout << "Unesite znak za linije u Board: ";
	char chh;
	cin >> chh;
	cout << endl;
	b.draw_line(p1, p2, chh);
	b.draw_line(p3, p4, chh);
	b.print();
}