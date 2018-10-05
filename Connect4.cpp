#include "Connect4.h"
#include <iostream>

using namespace std;

Connect4::Connect4()
{
	// this is private so never used
}

int Connect4::winner(char player)
{
	switch (player) {
		case 'X': return WINNER_X;
		case 'O': return WINNER_O;
	}
	return NO_WINNER;
}

Connect4::Connect4(int a, int b, int connect, bool wraparound)
{
	// set params
	x = a;
	y = b;
	this->connect = connect;
	this->wraparound = wraparound;
	lastMove = { -1, -1 };
	totalMoves = 0;
	curPlayer = -1;

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
	curPlayer = PLAYER_X;
	if ((a > y) || (a < 1)) return INSERT_FAIL;
	for (int i = x - 1; i > -1; i--)
	{
		if (chessboard[i][a - 1] == '.')
		{
			chessboard[i][a - 1] = 'X';
			lastMove = { i, a - 1 };
			++totalMoves;
			return SUCCESS;
		}
	}
	return INSERT_FAIL;
}

int Connect4::setO(int a)
{
	curPlayer = PLAYER_O;
	if ((a > y) || (a < 1)) return INSERT_FAIL;
	for (int i = x - 1; i > -1; i--)
	{
		if (chessboard[i][a - 1] == '.')
		{
			chessboard[i][a - 1] = 'O';
			lastMove = { i, a - 1 };
			++totalMoves;
			return SUCCESS;
		}
	}
	return INSERT_FAIL;
}

int Connect4::checkWinner()
{
	if (totalMoves >= x * y) return WINNER_TIE;
	if (checkHorizontal()) return winner(curPlayer);
	if (checkVertical()) return winner(curPlayer);
	if (checkDiagonal()) return winner(curPlayer);
	return NO_WINNER;
}

bool Connect4::checkHorizontal()
{
	int score, cur_x, cur_y;
	if (wraparound) {

	} else {

	}
	return score >= connect;
}

bool Connect4::checkVertical()
{
	int score, cur_x, cur_y;
	if (wraparound) {

	} else {

	}
	return score >= connect;
}

bool Connect4::checkDiagonal()
{
	int score, cur_x, cur_y;
	if (wraparound) {

	} else {

	}
	return score >= connect;
}