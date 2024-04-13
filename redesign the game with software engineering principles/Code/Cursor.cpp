#include "Cursor.h"

void Cursor::move() {
	if ((input == 's' || input == 'S') && board[CursorIndx[0] + 1][CursorIndx[1]]) {
		board[CursorIndx[0]][CursorIndx[1]] = cursorTemp;
		CursorIndx[0]++;
		cursorTemp = board[CursorIndx[0]][CursorIndx[1]];
		board[CursorIndx[0]][CursorIndx[1]] = 4;
	}
	else if ((input == 'w' || input == 'W') && board[CursorIndx[0] - 1][CursorIndx[1]]) {
		board[CursorIndx[0]][CursorIndx[1]] = cursorTemp;
		CursorIndx[0]--;
		cursorTemp = board[CursorIndx[0]][CursorIndx[1]];
		board[CursorIndx[0]][CursorIndx[1]] = 4;
	}
	else if ((input == 'd' || input == 'D') && board[CursorIndx[0]][CursorIndx[1] + 1]) {
		board[CursorIndx[0]][CursorIndx[1]] = cursorTemp;
		CursorIndx[1]++;
		cursorTemp = board[CursorIndx[0]][CursorIndx[1]];
		board[CursorIndx[0]][CursorIndx[1]] = 4;
	}
	else if ((input == 'a' || input == 'A') && board[CursorIndx[0]][CursorIndx[1] - 1]) {
		board[CursorIndx[0]][CursorIndx[1]] = cursorTemp;
		CursorIndx[1]--;
		cursorTemp = board[CursorIndx[0]][CursorIndx[1]];
		board[CursorIndx[0]][CursorIndx[1]] = 4;
	}
}

bool Cursor::click() {
	if (turn && cursorTemp == 1) {//O
		board[CursorIndex[0]][CursorIndx[1]] = 3;
		cursorTemp = 3;
		turn = 0;
	}
	else if (!turn && cursorTemp == 1) {//X
		board[CursorIndex[0]][CursorIndx[1]] = 2;
		cursorTemp = 2;
		turn = 1;
	}
}