#pragma once
#define NO_WINNER 0
#define WINNER_X 1
#define WINNER_O 2
#define SUCCESS 0
#define INSERT_FAIL 3

struct Pair { int a, b; };

class Connect4
{
	int x, y; // chessboard dimensions
	int connect; // by default we play connect4, but who knows
	bool wraparound; // def = no
	char **chessboard;
	Connect4(); // dummy ctor
	Pair lastMove; // keep track the location of last move

public:
	// ctor and dtor
	Connect4(int, int, int = 4, bool = false);
	~Connect4();

	// methods
	void display();
	int setX(int);
	int setO(int);
	int checkWinner();
};

