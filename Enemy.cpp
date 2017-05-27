//
// Created by Junius LEKGWARA on 2017/05/27.
//

#include "Enemy.hpp"

void Enemy::display() {
    MOVE: this->moveLeft();
    mvwaddch(this->getCurrentWin(), this->getYLoc(), this->getXLoc(), this->getCharacter());
    sleep(1000);
    if (this->alive)
        goto MOVE;
}

Enemy::Enemy(WINDOW *win, int y, int x, char c) {
    int height, width;
    this->setCurrentWin(win);
    this->setYLoc(y);
    this->setXLoc(x);
    this->setCharacter(c);
    getmaxyx(this->getCurrentWin(), height, width);
    this->setMaxHeight(height);
    this->setMaxWidth(width);
}

bool alive = true;
