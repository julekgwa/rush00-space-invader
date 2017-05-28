//
// Created by Junius LEKGWARA on 2017/05/27.
//

#ifndef RUSH00_PLAYER_HPP
#define RUSH00_PLAYER_HPP
#include <ncurses.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class GameEntity {
public:
    void moveUp(void);
    void moveDown(void);
    void moveLeft(void);
    void moveRight(void);
    void moveRight(int speed);
    void setMaxHeight(int h);
    void setMaxWidth(int w);
    int getMaxHeight(void);
    int getMaxWidth(void);
    void setYLoc(int y);
    void setXLoc(int x);
    void setCharacter(char c);
    char getCharacter(void);
    int getYLoc(void);
    int getXLoc(void);
    void setCurrentWin(WINDOW *win);
    WINDOW *getCurrentWin(void);
    bool alive;
    int score;
    int lives;

private:
    int xLoc, yLoc, maxHeight, maxWidth;
    char character;
    WINDOW *currentwin;
};


#endif //RUSH00_PLAYER_HPP
