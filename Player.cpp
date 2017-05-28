//
// Created by Junius LEKGWARA on 2017/05/27.
//

#include "Player.hpp"

Player::Player(WINDOW *win, int y, int x, char c) {
    int height, width;
    this->lives = 3;
    this->setCurrentWin(win);
    this->setYLoc(y);
    this->shots = -1;
    this->score = 0;
    this->setXLoc(x);
    this->setCharacter(c);
    getmaxyx(this->getCurrentWin(), height, width);
    this->setMaxHeight(height);
    this->setMaxWidth(width);
    keypad(this->getCurrentWin(), true);
}

Player::Player() {

}

void Player::display(Enemy enemies[], Enemy enemy1[]) {
    if (this->getMove() == ' ' && (this->shots + 1) < Enemy::total) {
        this->shots += 1;
        enemy1[this->shots].shot = true;
        enemy1[this->shots].show(this->getCurrentWin(), this->getYLoc(), this->getXLoc() + 1, '-');
    }
    int i = 0;
    while (i < 37) {
        if (enemies[i].getYLoc() == this->getYLoc() && enemies[i].getXLoc() == this->getXLoc() && enemies[i].alive) {
            enemies[i].lives = 0;
            enemies[i].alive = false;
            Enemy::totalAlive--;
            this->lives -= 1;
            mvwaddch(this->getCurrentWin(), this->getYLoc(), this->getXLoc(), ' ');
            this->setYLoc(this->getMaxHeight() / 2);
            this->setXLoc(5);
        }
        if (enemies[i].lives) {
            enemies[i].display(enemy1, this->shots);
        }
        i++;
    }
    if (Enemy::totalAlive <= 0) {
        this->lives = 0;
    }
    i = 0;
    while (i < this->shots) {
        if (enemy1[i].shot) {
            enemy1[i].display(enemy1, this->shots);
        }
        i++;
    }
    i = 0;
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
