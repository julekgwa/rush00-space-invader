//
// Created by Junius LEKGWARA on 2017/05/28.
//

#include "Bullet.hpp"

Bullet::Bullet(WINDOW *win, int y, int x, char c) {
    int height, width;
    this->lives = 1;
    this->shot = true;
    this->alive = true;
    this->setCurrentWin(win);
    this->setYLoc(y);
    this->setXLoc(x);
    this->setCharacter(c);
    getmaxyx(this->getCurrentWin(), height, width);
    this->setMaxHeight(height);
    this->setMaxWidth(width);
}

Bullet::Bullet() {
    this->shot = false;
    this->alive = false;
}

void Bullet::display(int y, int x) {
//   if (this->shot) {
//       this->setYLoc(player.getYLoc());
//       this->setXLoc(player.getXLoc() + 10);
//       mvwaddch(this->getCurrentWin(), this->getYLoc(), this->getXLoc(), this->getCharacter());
//       this->shot = false;
//       this->moveRight(2);
//   } else {
//    this->moveRight(2);
    mvwaddch(this->getCurrentWin(), y, x + 10, '-');
//   }
}
