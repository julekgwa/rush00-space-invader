//
// Created by Junius LEKGWARA on 2017/05/27.
//

#include "Enemy.hpp"

void Enemy::display() {
    if (this->type == 'E')
        this->moveLeft();
    else if (this->type == 'B')
        this->moveRight(3);
    mvwaddch(this->getCurrentWin(), this->getYLoc(), this->getXLoc(), this->getCharacter());
}

Enemy::Enemy(WINDOW *win, int y, int x, char c) {
    int height, width;
    this->lives = 1;
    this->alive = true;
    this->type = 'E';
    this->shot = false;
    this->setCurrentWin(win);
    this->setYLoc(y);
    this->setXLoc(x);
    this->setCharacter(c);
    getmaxyx(this->getCurrentWin(), height, width);
    this->setMaxHeight(height);
    this->setMaxWidth(width);
}

Enemy::Enemy() {
    this->type = 'B';
    this->shot = false;
}
void Enemy::show(WINDOW *win, int y, int x, char c) {
    int height, width;
    this->lives = 1;
    this->alive = true;
    this->type = 'B';
    this->shot = true;
    this->setCurrentWin(win);
    this->setYLoc(y);
    this->setXLoc(x);
    this->setCharacter(c);
    getmaxyx(this->getCurrentWin(), height, width);
    this->setMaxHeight(height);
    this->setMaxWidth(width);
}
bool alive = true;
