#include "Player.h"

Player::Player(bool playerType){
	type = playerType;
}

bool Player::getType() {
	return type;
}