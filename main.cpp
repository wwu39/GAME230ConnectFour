#include<string>
#include <stdexcept>
#include <iostream>
#include <string>
#include "connect4.h"

using namespace std;

int getInt(string str)
{
	try {
		return stoi(str);
	}
	catch (const invalid_argument& e) {
		return -1;
	}
}

int main()
{
	cout << "Let's play Connect Four!" << endl;
	Connect4 * game = new Connect4(6, 7);
	game->display();
	string input_X, input_O;
	int winner = NO_WINNER;
	while (1)
	{
		cout << "Player X's turn! Type the column number to insert a piece: ";
		cin >> input_X;
		while (game->setX(getInt(input_X)))
		{
			cout << "Oops! I don't understand you, please reenter: ";
			cin >> input_X;
		}
		game->display();
		winner = game->checkWinner();
		if (winner) break;

		cout << "Player O's turn! Type the column number to insert a piece: ";
		cin >> input_O;
		while (game->setO(getInt(input_O)))
		{
			cout << "Oops! I don't understand you, please reenter: ";
			cin >> input_O;
		}
		game->display();
		winner = game->checkWinner();
		if (winner) break;
	}
	switch (winner) {
		case WINNER_X: cout << "Winner is X!!!" << endl; break;
		case WINNER_O: cout << "Winner is O!!!" << endl; break;
		case WINNER_TIE: cout << "Draw." << endl; break;
		default: cout << "ERROR: This never happened."; break;
	}
	system("pause");
	delete game;
	return 0;
}