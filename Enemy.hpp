//
// Created by Junius LEKGWARA on 2017/05/27.
//

#ifndef RUSH00_ENEMY_H
#define RUSH00_ENEMY_H

#include "GameEntity.hpp"
#include <unistd.h>

class Enemy: public GameEntity {
public:
    Enemy(WINDOW *win, int y, int x, char c);
    Enemy();
    void show(WINDOW *win, int y, int x, char c);
    void display(Enemy bullets[], int totalShots);
    bool shot;
    char type;
    static int total;
};


#endif //RUSH00_ENEMY_H
