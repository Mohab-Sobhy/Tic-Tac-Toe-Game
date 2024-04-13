#pragma once
#include <string>
#include "Player.h"
using namespace std;

class humanPlayer : public Player {
private:
	string name;
	int score;
public:
	humanPlayer(bool playerType, string playerName);
	string getName();
	int getScore();
};