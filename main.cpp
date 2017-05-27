#include <iostream>
#include <ncurses.h>

int main() {
    initscr();
    int height, width, starty, startx;
    getmaxyx(stdscr, height, width);
    starty = (height - (height - 2)) / 2;    /* Calculating for a center placement */
    startx = (width - (width - 2)) / 2;
    height -= 2;
    width -= 2;
    WINDOW *win = newwin(height, width, starty, startx);
    refresh();
    box(win, 0, 0);
    wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(win);
    int  c = getch();
    (void)c;
    endwin();
    return 0;
}