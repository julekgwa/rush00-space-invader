//
// Created by Junius LEKGWARA on 2017/05/27.
//

#include "Player.hpp"

Player::Player(WINDOW *win, int y, int x, char c) {
    int height, width;
    this->setCurrentWin(win);
    this->setYLoc(y);
    this->setXLoc(x);
    this->setCharacter(c);
    getmaxyx(this->getCurrentWin(), height, width);
    this->setMaxHeight(height);
    this->setMaxWidth(width);
    keypad(this->getCurrentWin(), true);
}

void Player::display() {
    mvwaddch(this->getCurrentWin(), this->getYLoc(), this->getXLoc(), this->getCharacter());
}

int Player::getMove() {
    int key = wgetch(this->getCurrentWin());
    switch (key) {
        case KEY_UP:
            this->moveUp();
            break;
        case KEY_DOWN:
            this->moveDown();
            break;
        case KEY_LEFT:
            this->moveLeft();
            break;
        case KEY_RIGHT:
            this->moveRight();
            break;
        default:
            break;
    }
    return key;
}
