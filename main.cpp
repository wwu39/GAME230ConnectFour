#include<string>
#include <stdexcept>
#include "connect4.h"

using namespace std;

int main()
{
	cout << "Let's play Connect Four!" << endl;
	Connect4 game{6, 7};
	game.display();
	int input_X, input_O;
	cout << "Player X's turn! Type the column number to insert a piece: ";
	cin >> input_X;
	// to be continued
	return 0;
}