#include "Connect4.h"
#include <iostream>

using namespace std;

Connect4::Connect4()
{
	// this is private so never used
}

Connect4::Connect4(int a, int b, int connect, bool wraparound)
{
	// set params
	x = a;
	y = b;
	this->connect = connect;
	this->wraparound = wraparound;
	lastMove = { -1, -1 };

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

int Connect4::setX(int a)
{
	if ((a > y) || (a < 1)) return INSERT_FAIL;
	for (int i = x - 1; i > -1; i--)
	{
		if (chessboard[i][a - 1] == '.')
		{
			chessboard[i][a - 1] = 'X';
			lastMove = { i, a - 1 };
			return SUCCESS;
		}
	}
	return INSERT_FAIL;
}

int Connect4::setO(int a)
{
	if ((a > y) || (a < 1)) return INSERT_FAIL;
	for (int i = x - 1; i > -1; i--)
	{
		if (chessboard[i][a - 1] == '.')
		{
			chessboard[i][a - 1] = 'O';
			lastMove = { i, a - 1 };
			return SUCCESS;
		}
	}
	return INSERT_FAIL;
}

int Connect4::checkWinner()
{
	return NO_WINNER;
}
