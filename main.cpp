#include <iostream>
#include "Header.h"

using namespace std;

int main() {
	cout << "Let's play Connect Four!" << endl;
	Dims size {6, 7};
	for (int i = 0; i < size.y; ++i) cout << i + 1;
	cout << endl;
	for (int i = 0; i < size.x; ++i) {
		for (int j = 0; j < size.y; ++j) {
			cout << ".";
		}
		cout << endl;
	}
	cout << "Player X's turn! Type the column number to insert a piece: ";
	cin >> inputs.X;
	return 0;
}