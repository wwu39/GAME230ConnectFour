#pragma once
#define NO_WINNER 0
#define WINNER_X 1
#define WINNER_O 2
#define WINNER_TIE 3
#define SUCCESS 0
#define INSERT_FAIL 3
#define DELETE_FAIL 4
#define PLAYER_X 'X'
#define PLAYER_O 'O'

struct Pair { int x, y; };
struct PairSum { int X, O; };

class Connect4
{
	int x, y; // chessboard dimensions
	int connect; // by default we play connect4, but who knows
	bool wraparound; // def = no
	char **chessboard;
	Connect4(); // dummy ctor
	int totalMoves;

	// private helpers
	int winner(char);
	bool checkHorizontal(char);
	bool checkVertical(char);
	bool checkDiagonal(char);
	// c++ % yields negative# so I need this
	int posmod(int a, int n) { return (a % n + n) % n; };

public:
	// ctor and dtor
	Connect4(int, int, int = 4, bool = false);
	~Connect4();

	Pair lastMove; // keep track the location of last move

	// methods
	void display();
	int setX(int);
	int setO(int);
	int checkWinner(char);
	int checkWinnerDel(char, int);
	int delX(int);
	int delO(int);
	int AIMove();
	PairSum sum();
};