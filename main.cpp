#include <string>
#include <stdexcept>
#include <iostream>
#include <string>
#include "connect4.h"

using namespace std;

// global variables
static Connect4 * game;
static const string errormsg = "Oops! I don't understand you, please reenter: ";
static const string errormsg_rm = "Can't remove a piece here, please reenter: ";
static const string errormsg_ins = "Can't insert a piece here, please reenter: ";
static string input;

// some helper functions
int getPosInt(string str)
{
	try {
		return stoi(str);
	}
	catch (const invalid_argument& e) {
		return -1;
	}
}

bool isBool(char ch)
{
	switch (ch) {
		case 'Y': case 'y': case 'N': case 'n': return true;
		default: return false;
	}
}

int min(int a, int b) { return a < b ? a : b; }

// main, I guess
int main()
{
	cout << "Let's play Connect Four!" << endl;
	system("pause");
	cout << endl;
	// default settings
	int height = 6, width = 7, requiredToWin = 4;
	bool wraparound = false, eraseMod = false;
	while (1) {
		cout << "*****Default Settings*****" << endl
			<< "Chessboard size: " << height << "¡Á" << width << endl
			<< "Required to win: " << requiredToWin << endl
			<< "Wrap around: " << (wraparound ? "Yes" : "No") << endl
			<< "Erase mode: " << (eraseMod ? "Yes" : "No") << endl
			<< "Wanna change settings? (Y/N)" << endl;
		cin >> input;
		while (!isBool(input[0]) || input.length() > 1) {
			cout << errormsg;
			cin >> input;
		}

		if (input[0] == 'Y' || input[0] == 'y') { // change settings
			cout << "Chessboard Height (4-20): ";
			cin >> input; // yes we can use input again
			height = getPosInt(input);
			while (height < 4 || height > 20) {
				cout << errormsg;
				cin >> input;
				height = getPosInt(input);
			}

			cout << "Chessboard Width (4-20): ";
			cin >> input;
			width = getPosInt(input);
			while (width < 4 || width > 20) {
				cout << errormsg;
				cin >> input;
				width = getPosInt(input);
			}

			cout << "Require to win (3-" << min(height, width) << "): ";
			cin >> input;
			requiredToWin = getPosInt(input);
			while (requiredToWin < 3 || requiredToWin > min(height, width)) {
				cout << errormsg;
				cin >> input;
				requiredToWin = getPosInt(input);
			}

			cout << "Wrap around? (Y/N): ";
			cin >> input;
			while (!isBool(input[0]) || input.length() > 1) {
				cout << errormsg;
				cin >> input;
			}
			wraparound = (input[0] == 'Y' || input[0] == 'y') ? true : false;

			cout << "Erase Mode? (Y/N): ";
			cin >> input;
			while (!isBool(input[0]) || input.length() > 1) {
				cout << errormsg;
				cin >> input;
			}
			eraseMod = (input[0] == 'Y' || input[0] == 'y') ? true : false;

		}

		// create a new game
		game = new Connect4(height, width, requiredToWin, wraparound);
		game->display();
		string input_X, input_O;
		int winner = NO_WINNER;
		while (1)
		{
			cout << "Player X's turn! ";
			if (eraseMod && game->sum().X) {
				cout << "Remove a piece? (Y/N): ";
				cin >> input;
				while (!isBool(input[0]) || input.length() > 1) {
					cout << errormsg;
					cin >> input;
				}
				if (input[0] == 'Y' || input[0] == 'y') { // erase a piece
					cout << "Type the column number to remove a piece: ";
					cin >> input_X;
					while (game->delX(getPosInt(input_X)))
					{
						cout << errormsg_rm;
						cin >> input_X;
					}
					game->display();
					int col = getPosInt(input_X);
					winner = game->checkWinnerDel(col);
					goto skipInsertX;
				}
			}
			cout << "Type the column number to insert a piece: ";
			cin >> input_X;
			while (game->setX(getPosInt(input_X)))
			{
				cout << errormsg_ins;
				cin >> input_X;
			}
			game->display();
			winner = game->checkWinner(PLAYER_X);
		skipInsertX:
			if (winner) break;

			cout << "Player O's turn! ";
			if (eraseMod && game->sum().O) {
				cout << "Remove a piece? (Y/N): ";
				cin >> input;
				while (!isBool(input[0]) || input.length() > 1) {
					cout << errormsg;
					cin >> input;
				}
				if (input[0] == 'Y' || input[0] == 'y') { // erase a piece
					cout << "Type the column number to remove a piece: ";
					cin >> input_O;
					while (game->delO(getPosInt(input_O)))
					{
						cout << errormsg_rm;
						cin >> input_O;
					}
					game->display();
					int col = getPosInt(input_O);
					winner = game->checkWinnerDel(col);
					goto skipInsertO;
				}
			}
			cout << "Type the column number to insert a piece: ";
			cin >> input_O;
			while (game->setO(getPosInt(input_O)))
			{
				cout << errormsg_ins;
				cin >> input_O;
			}
			game->display();
			winner = game->checkWinner(PLAYER_O);
		skipInsertO:			
			if (winner) break;
		}
		switch (winner) {
		case WINNER_X: cout << "Winner is X!!!" << endl; break;
		case WINNER_O: cout << "Winner is O!!!" << endl; break;
		case WINNER_TIE: cout << "Draw." << endl; break;
		default: cout << "ERROR: This never happened."; break;
		}
		delete game;
		game = nullptr;

		// restart game
		cout << "Play again? (Y/N): ";
		cin >> input;
		while (!isBool(input[0]) || input.length() > 1) {
			cout << errormsg;
			cin >> input;
		}
		if (input[0] == 'N' || input[0] == 'n') break;
	}
	return 0;
}