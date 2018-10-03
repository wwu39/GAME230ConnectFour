#include "Connect4.h"

Connect4::Connect4()
{
	// this is private so never used
}

Connect4::Connect4(int a, int b)
{
	// set dimensions
	x = a;
	y = b;

	// create chessboard
	chessboard = new char*[x];
	for (int i = 0; i < x; ++i)
		chessboard[i] = new char[y];

	// initialize chessboard
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < y; ++j)
			chessboard[i][j] = '.';
}


Connect4::~Connect4()
{
	for (int i = 0; i < x; ++i) delete chessboard[i];
	delete chessboard;
}

void Connect4::display()
{
	for (int i = 0; i < y; ++i) cout << i + 1;
	cout << endl;
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
			cout << chessboard[i][j];
		cout << endl;
	}
}

void Connect4::setX(int)
{
}

void Connect4::setY(int)
{
}

void Connect4::checkWinner()
{
}
