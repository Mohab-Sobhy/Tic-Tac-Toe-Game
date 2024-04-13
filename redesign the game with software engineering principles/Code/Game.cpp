#include "Game.h"

Game::Game() {
    if (CorF == 2) {
        system("CLS");
        cout << "use \'w\' \'a\' \'s\' \'d\' to move and \'c\' to choose\n(remeber to change your keyboard to english if isn't)\n";
        XO friendXO;
        while (!friendXO.checkWin()) {
            friendXO.printBoard();
            input = _getch();
            friendXO.setInput(input);
            if (input == 99 || input == 67)
                friendXO.select();
            else
                friendXO.moveCursor();
            system("CLS");
        }
        friendXO.getTurn() ? cout << "-> \033[1;31mX player\033[0m is the winner <-\n" : cout << "-> \033[1;32mO player\033[0m is the winner <-\n";
    }
    //------------------------------------->computer
    else {
        system("CLS");
        cout << "use \'w\' \'a\' \'s\' \'d\' to move and \'c\' to choose\n(remeber to change your keyboard to english if isn't)\n";
        XO computerXO;
        while (!computerXO.checkWin()) {
            computerXO.printBoard();
            if (computerXO.getTurn())
                computerXO.randomPlay();

            else {
                input = _getch();
                computerXO.setInput(input);
                if (input == 99 || input == 67)
                    computerXO.select();
                else
                    computerXO.moveCursor();
            }
            system("CLS");
        }
        computerXO.getTurn() ? cout << "-> \033[1;31mYou\033[0m are the winner <-\n" : cout << "-> \033[1;32mComputer\033[0m is the winner <-\n";

    }
    cout << "\nDo you want to play again (y/n)\n";
    char s;
    s = _getch();
    if (s == 'y')
        again = 1;
    system("CLS");
} while (again);
}

bool Game::checkWin() {
	for (int i = 1; i < 4; i++) {
		if ()
	}