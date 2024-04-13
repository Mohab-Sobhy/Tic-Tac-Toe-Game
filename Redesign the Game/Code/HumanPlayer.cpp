#include "HumanPlayer.h"

humanPlayer::humanPlayer(bool playerType, string playerName) {
	type = playerType;
	name = playerName;
}

string humanPlayer::getName() {
	return name;
}

int humanPlayer::getScore() {
	return score;
}