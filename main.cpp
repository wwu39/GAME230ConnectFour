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
	Connect4 game(6, 7);
	game.display();
	string input_X, input_O;
	while (1)
	{
		cout << "Player X's turn! Type the column number to insert a piece: ";
		cin >> input_X;
		while (game.setX(getInt(input_X)))
		{
			cout << "Oops! I don't understand you, please reenter: ";
			cin >> input_X;
		}
		game.display();
		if (game.checkWinner()) break;

		cout << "Player O's turn! Type the column number to insert a piece: ";
		cin >> input_O;
		while (game.setO(getInt(input_O)))
		{
			cout << "Oops! I don't understand you, please reenter: ";
			cin >> input_O;
		}
		game.display();
		if (game.checkWinner()) break;
	}
	// to be continued
	system("pause");
	return 0;
}