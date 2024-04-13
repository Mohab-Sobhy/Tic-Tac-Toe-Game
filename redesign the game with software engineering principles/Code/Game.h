#pragma once
#include <iostream>
using namespace std;

class Game {
private:
	bool turn;
	char input;
	string stringInput;
	Board mainBoard();
	Cursor mainCursor;

public:
	Game();
	bool checkWin();
	void setInput();
	void setStringInput();
	char getInput();
	string getStringInput();
	bool getTurn();
};

