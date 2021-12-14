#include <iostream>
#include <math.h>
#include "Board.hpp"

using namespace std;


Board::Board()
{
	row = 10;
	coll = 20;
}
Board::Board(Board& b)
{
	row = b.row; coll = b.coll;

	if (b.board)
	{
		board = new char* [row];

		for (int i = 0; i < row; i++)
			board[i] = new char[coll];

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < coll; j++)
			{
				board[i][j] = b.board[i][j];
			}
		}
	}
}
Board::Board(Board&& b) : row(b.row), coll(b.coll), board(b.board)
{
	delete[] board;
	board = b.board;
	b.board = nullptr;
}
Board::~Board()
{
	for (int r = 0; r < row; r++)
		delete[] board[r];
	delete[] board;
}


void Board::draw_char(const struct Point& p, char chh)
{
	board[int(p.x)][int(p.y)] = chh;
}
void Board::draw_up_line(const struct Point& p, char chh)
{
	int x = p.x;
	int y = p.y;
	for(int i=y;i!=(coll-2);i++)
		board[x][i] = chh;
	
}
void Board::draw_line(const struct Point& p, const struct Point& p2, char chh)
{
	int x1 = p.x, y1 = p.y;
	int x2 = p2.x, y2 = p2.y;

	int flag = y1;

	if (x1 == x2)
	{
		for (int i = y1; i <= y2; i++)
		{
			board[x1][i] = chh;
		}
	}
	else if (y1 == y2)
	{
		for (int i = x1; i <= x2; i++)
		{
			board[i][y1] = chh;
		}
	}
	else
	{
		for (int i = x1; i <= x2; i++)
		{
			board[flag][i] = chh;
			flag++;
		}
	}
}


void Board::Matrix()
{
	double r = row, c = coll;
	this->board = new char* [r];

	for (int i = 0; i < r; i++)
		this->board[i] = new char[c];

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if ((i == 0) || (i == int(r) - 1) || (j == 0) || (j == int(c) - 1))
			{
				this->board[i][j] = ch;
			}
			else
				this->board[i][j] = ' ';
		}
	}
}
void Board::print()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < coll; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}


Point Point::point(Board& b, int q)
{
	Point p;
	double x_np = 0, y_np = 0;
	double x, y;
	while(1)
	{
		cout << "Za tocku "<< q << " unesi kordinatu x: " << endl; cin >> x;
		cout << "Za tocku " << q << " unesi kordinatu y: " << endl; cin >> y;

		for (int i = 0; i < b.row; i++)
		{
			for (int j = 0; j < b.coll; j++)
			{
				if (x >= x_np and x <= b.row and y >= y_np and y <= b.coll) { p.x = x; p.y = y; return p; }
					
			}
		}
	}
}


