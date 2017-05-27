#include "Player.hpp"

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

    Player *p = new Player(win, height, width, '*');
    do {
        p->display();
        wrefresh(win);
    } while (p->getMove() != 'x');

    getch();
    endwin();
    return 0;
}