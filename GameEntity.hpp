//
// Created by Junius LEKGWARA on 2017/05/27.
//

#ifndef RUSH00_PLAYER_HPP
#define RUSH00_PLAYER_HPP
#include <ncurses.h>

class GameEntity {
public:
    void moveUp(void);
    void moveDown(void);
    void moveLeft(void);
    void moveRight(void);
    void setLives(int lives);
    int getLives(void);
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

private:
    int xLoc, yLoc, maxHeight, maxWidth;
    char character;
    int lives;
    WINDOW *currentwin;
};


#endif //RUSH00_PLAYER_HPP
