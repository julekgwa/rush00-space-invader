//
// Created by Junius LEKGWARA on 2017/05/27.
//

#include "GameEntity.hpp"

void GameEntity::moveUp() {
    mvwaddch(this->currentwin, this->yLoc, this->xLoc, ' ');
    this->yLoc -= 2;
    if (this->yLoc < 1) {
        this->yLoc = 1;
    }
}

void GameEntity::moveDown() {
    mvwaddch(this->currentwin, this->yLoc, this->xLoc, ' ');
    this->yLoc += 2;
    if (this->yLoc > maxHeight - 2) {
        this->yLoc = maxHeight - 2;
    }
}

void GameEntity::moveLeft() {
    mvwaddch(this->currentwin, this->yLoc, this->xLoc, ' ');
    this->xLoc -= 2;
    if (this->xLoc < 1) {
        this->xLoc = maxWidth - 2;
        this->yLoc = 4 + (rand() % (int)(maxHeight - 4 + 1));
    }
}

void GameEntity::moveRight() {
    mvwaddch(this->currentwin, this->yLoc, this->xLoc, ' ');
    this->xLoc += 2;
    if (this->xLoc > maxWidth - 2) {
        this->xLoc = maxWidth - 2;
    }
}

void GameEntity::moveRight(int speed) {
    mvwaddch(this->currentwin, this->yLoc, this->xLoc, ' ');
    this->xLoc += speed;
    if (this->xLoc > maxWidth - 2) {
        mvwaddch(this->currentwin, this->yLoc, this->xLoc, ' ');
    }
}

void GameEntity::setMaxHeight(int h) {
    this->maxHeight = h;
}

void GameEntity::setMaxWidth(int w) {
    this->maxWidth = w;
}

int GameEntity::getMaxHeight() {
    return this->maxHeight;
}

int GameEntity::getMaxWidth() {
    return this->maxWidth;
}

void GameEntity::setYLoc(int y) {
    this->yLoc = y;
}

void GameEntity::setXLoc(int x) {
    this->xLoc = x;
}

void GameEntity::setCurrentWin(WINDOW *win) {
    this->currentwin = win;
}

int GameEntity::getYLoc() {
    return this->yLoc;
}

int GameEntity::getXLoc() {
    return this->xLoc;
}

void GameEntity::setCharacter(char c) {
    this->character = c;
}

char GameEntity::getCharacter() {
    return this->character;
}

WINDOW *GameEntity::getCurrentWin() {
    return this->currentwin;
}