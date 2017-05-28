//
// Created by Junius LEKGWARA on 2017/05/28.
//

#ifndef RUSH00_BULLET_HPP
#define RUSH00_BULLET_HPP

#include "GameEntity.hpp"

class Bullet: public GameEntity {
public:
    Bullet(WINDOW *win, int y, int x, char c);
    Bullet();
    void display(int y, int x);
    bool shot;
};


#endif //RUSH00_BULLET_HPP
