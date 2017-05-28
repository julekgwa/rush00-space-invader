//
// Created by Junius LEKGWARA on 2017/05/27.
//

#ifndef RUSH00_PLAYER_H
#define RUSH00_PLAYER_H

#include "GameEntity.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"


class Player: public GameEntity {
public:
    Player(WINDOW *win, int y, int x, char c);
    Player();
    void display(Enemy &enemy, Enemy enemy1[]);
    int getMove();
    int shots;
};


#endif //RUSH00_PLAYER_H
