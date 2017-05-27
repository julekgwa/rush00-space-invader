//
// Created by Junius LEKGWARA on 2017/05/27.
//

#include "Player.hpp"

void Player::display() {
    mvwaddch(this->currentwin, this->yLoc, this->xLoc, this->character);
}

Player::Player(WINDOW *win, int y, int x, char c) {
    this->currentwin = win;
    this->yLoc = y;
    this->xLoc = x;
    this->character = c;
    getmaxyx(currentwin, this->maxHeight, this->maxWidth);
    keypad(currentwin, true);
}

void Player::moveUp() {
    mvwaddch(this->currentwin, this->yLoc, this->xLoc, ' ');
    this->yLoc--;
    if (this->yLoc < 1) {
        this->yLoc = 1;
    }
}

void Player::moveDown() {
    mvwaddch(this->currentwin, this->yLoc, this->xLoc, ' ');
    this->yLoc++;
    if (this->yLoc > maxHeight - 2) {
        this->yLoc = maxHeight - 2;
    }
}

void Player::moveLeft(){
    mvwaddch(this->currentwin, this->yLoc, this->xLoc, ' ');
    this->xLoc--;
    if (this->xLoc < 1) {
        this->xLoc = 1;
    }
}

void Player::moveRight(){
    mvwaddch(this->currentwin, this->yLoc, this->xLoc, ' ');
    this->xLoc++;
    if (this->xLoc > maxWidth - 2) {
        this->xLoc = maxWidth - 2;
    }
}

int Player::getMove() {
    int key = wgetch(this->currentwin);
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
