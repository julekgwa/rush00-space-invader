//
// Created by Junius LEKGWARA on 2017/05/27.
//

#include "Enemy.hpp"

void Enemy::display(Enemy bullets[], int totalShots) {
    if (this->type == 'E')
        this->moveLeft();
    else if (this->type == 'B')
        this->moveRight(3);
    int i = 0;
    while (i < totalShots) {
        if (bullets[i].shot) {
            if (bullets[i].getYLoc() == this->getYLoc() && bullets[i].getXLoc() == this->getXLoc() && this->alive &&
                this->type == 'E') {
                this->lives = 0;
                this->alive = false;
                mvwaddch(this->getCurrentWin(), this->getYLoc(), this->getXLoc(), ' ');
            }
        }
        i++;
    }
    if (this->alive)
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
    this->total++;
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
int Enemy::total = 0;

