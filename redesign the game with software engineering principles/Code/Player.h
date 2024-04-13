#pragma once

class Player {
protected:
	bool type;// 0->X | 1->O
	int numOfWins;
public:
	Player(bool playerType);
	bool getType();
};