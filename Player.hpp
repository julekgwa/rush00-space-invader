//
// Created by Junius LEKGWARA on 2017/05/27.
//

#ifndef RUSH00_PLAYER_HPP
#define RUSH00_PLAYER_HPP
#include <ncurses.h>

class Player {
public:
    Player(WINDOW *win, int y, int x, char c);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int  getMove();
    void display();

private:
    int xLoc, yLoc, maxHeight, maxWidth;
    char character;
    WINDOW *currentwin;
};


#endif //RUSH00_PLAYER_HPP
