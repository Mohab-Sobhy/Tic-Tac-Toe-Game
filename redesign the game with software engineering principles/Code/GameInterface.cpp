#include<iostream>
#include "GameInterface.h"
#include "Player.h";
using namespace std;

void GameInterface::printWelcome(){
    cout << "Welcome to my tic tac toe game\n\n";
    cout << "Do you want to play against computer or your friend?\n";
    cout << "1- with computer\n";
    cout << "1- with my friend\n";
    cout << "Select: ";
}

void GameInterface::printPlayerForm(Player playerObj) {
    cout << "Player ";
    playerObj.getType() ? cout << 'O' : cout << 'X';
    cout << "Name: ";
}

void GameInterface::printReplay() {
    cout << "Do you want to play again with same person?";
}