//
// Created by Junius LEKGWARA on 2017/05/27.
//

#ifndef RUSH00_PLAYER_H
#define RUSH00_PLAYER_H

#include "GameEntity.hpp"
#include "Enemy.hpp"


class Player: public GameEntity {
public:
    Player(WINDOW *win, int y, int x, char c);
    void display(Enemy *enemy);
    int getMove();
};


#endif //RUSH00_PLAYER_H
