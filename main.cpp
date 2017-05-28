#include "GameEntity.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

int main() {
    initscr();
    int height, width, starty, startx;
    getmaxyx(stdscr, height, width);
    curs_set(0);
    starty = (height - (height - 2)) / 2;    /* Calculating for a center placement */
    startx = (width - (width - 2)) / 2;
    height -= 2;
    width -= 2;
    WINDOW *win = newwin(height, width, starty, startx);
    refresh();
    box(win, 0, 0);
    wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(win);

    halfdelay(4);
    Enemy enemy(win, height / 2, width - 20, 'R');
    Enemy bullet[20];
    Player *p = new Player(win, height / 2, 5, '>');
    do {
        p->display(enemy, bullet);
        wrefresh(win);
    } while (p->getMove() != 'x' && p->lives);

    getch();
    endwin();
    return 0;
}