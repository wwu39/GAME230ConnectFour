#pragma once
#include <iostream>

using namespace std;

class Connect4
{
	int x;
	int y;
	char **chessboard;
	Connect4();

public:
	// ctor and dtor
	Connect4(int, int);
	~Connect4();

	// methods
	void display();
	void setX(int);
	void setY(int);
	void checkWinner();
};

