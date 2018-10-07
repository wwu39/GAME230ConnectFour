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
			++totalMoves;
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
			++totalMoves;
			return SUCCESS;
		}
	}
	return INSERT_FAIL;
}

int Connect4::checkWinner(char player)
{
	if (totalMoves >= x * y) return WINNER_TIE;
	if (checkHorizontal(player)) return winner(player);
	if (checkVertical(player)) return winner(player);
	if (checkDiagonal(player)) return winner(player);
	return NO_WINNER;
}

bool Connect4::checkHorizontal(char player)
{
	int score = 1;
	if (wraparound) {

	} else {
		// sum left
		for (int i = lastMove.y - 1; i >= 0; --i) {
			if (chessboard[lastMove.x][i] == player) ++score;
			else break;
			if (score >= connect) return true;
		}
		// sum right
		for (int i = lastMove.y + 1; i < y; ++i) {
			if (chessboard[lastMove.x][i] == player) ++score;
			else break;
			if (score >= connect) return true;
		}
	}
	return false;
}

bool Connect4::checkVertical(char player)
{
	int score = 1;
	if (wraparound) {

	}
	else {
		// sum upwards
		for (int i = lastMove.x - 1; i >= 0; --i) {
			if (chessboard[i][lastMove.y] == player) ++score;
			else break;
			if (score >= connect) return true;
		}
		// sum downwards
		for (int i = lastMove.x + 1; i < x; ++i) {
			if (chessboard[i][lastMove.y] == player) ++score;
			else break;
			if (score >= connect) return true;
		}
	}
	return false;
}

bool Connect4::checkDiagonal(char player)
{
	int score = 1;
	if (wraparound) {

	} else{
		// sum up-left
		for (int i = lastMove.x - 1, j = lastMove.y - 1;
			(i >= 0) && (j >= 0); --i, --j) {
			if (chessboard[i][j] == player) ++score;
			else break;
			if (score >= connect) return true;
		}
		// sum down-right
		for (int i = lastMove.x + 1, j = lastMove.y + 1;
			(i < x) && (j < y); ++i, ++j) {
			if (chessboard[i][j] == player) ++score;
			else break;
			if (score >= connect) return true;
		}
		// sum up-right
		score = 1;
		for (int i = lastMove.x - 1, j = lastMove.y + 1;
			(i >= 0) && (j < y); --i, ++j) {
			if (chessboard[i][j] == player) ++score;
			else break;
			if (score >= connect) return true;
		}
		// sum down-left
		for (int i = lastMove.x + 1, j = lastMove.y - 1;
			(i < x) && (j >= 0); ++i, --j) {
			if (chessboard[i][j] == player) ++score;
			else break;
			if (score >= connect) return true;
		}
	}
	return false;
}