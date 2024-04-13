#include "Board.h"

bool Board::AreThreeElementsEqual(int a, int b, int c) {
	if (a == b && b == c)
		return 1;
	return 0;
}

Board::Board(Game pointer) {
	gamePointer = pointer;
	board = new int* [5];
	for (int i = 0; i < 5; i++) {
		board[i] = new int[5];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 0 || i == 4 || j == 0 || j == 4) {
				board[i][j] = 0;
			}
			else
				board[i][j] = 1;
		}
	}
	board[1][1] = 4;// cursor
}

void Board::display() {
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (board[i][j] == 1)
				cout << "\033[1;46m   \033[0m";
			else if (board[i][j] == 2)
				cout << "\033[1;46m X \033[0m";
			else if (board[i][j] == 3)
				cout << "\033[1;46m O \033[0m";
			else {
				if (Game::getTurn()) {
					if (cursorTemp == 2)
						cout << "\033[1;42m X \033[0m";
					else if (cursorTemp == 3)
						cout << "\033[1;42m O \033[0m";
					else if (cursorTemp == 1)
						cout << "\033[1;42m   \033[0m";
				}

				else {
					if (cursorTemp == 2)
						cout << "\033[1;41m X \033[0m";
					else if (cursorTemp == 3)
						cout << "\033[1;41m O \033[0m";
					else if (cursorTemp == 1)
						cout << "\033[1;41m   \033[0m";
				}
			}
		}
		cout << "\n";
	}
}

bool Board::isEqualRow(int row_num) {
	if (AreThreeElementsEqual(board[row_num][1], board[row_num][2], board[row_num][3]) && (board[row_num][3] == 2 || board[row_num][3] == 3))
		return 1;
	return 0;
}

bool Board::isEqualColumn(int column_num) {
	if (AreThreeElementsEqual(board[column_num][1], board[column_num][2], board[column_num][3]) && (board[column_num][3] == 2 || board[column_num][3] == 3))
		return 1;
	return 0;
}

bool Board::isEqualDiameter(bool mainOrSecondary) {
	if (AreThreeElementsEqual(board[1][1], board[2][2], board[3][3]) && (board[2][2] == 2 || board[2][2] == 3))
		return 1;
	else if (AreThreeElementsEqual(board[1][3], board[2][2], board[3][1]) && (board[2][2] == 2 || board[2][2] == 3))
		return 1;
	return 0;
}