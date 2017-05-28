#include "GameEntity.hpp"
#include "Player.hpp"

void hud(int height, int lives, int score) {
    mvprintw(height, 0, "--------------------------------------------------");
    mvprintw(height + 1, 0, "Lives: %d | score: %d", lives, score);
    refresh();
}

int main() {
    srand( ( unsigned int ) time( NULL ) );
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
//    box(win, 0, 0);
//    wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(win);

    halfdelay(4);
    Enemy enemies[37] = {Enemy(win, height / 2, width - 20, '{'),
                         Enemy(win, height / 3, width + 20, '{'),
                         Enemy(win, height / 4, width + 40, '{'),
                         Enemy(win, height / 2, width + 50, '{'),
                         Enemy(win, height / 5, width + 70, '{'),
                         Enemy(win, height / 3, width + 10, '{'),
                         Enemy(win, height / 7, width + 50, '{'),
                         Enemy(win, height / 3, width + 80, '{'),
                         Enemy(win, height / 2, width + 90, '{'),
                         Enemy(win, height / 4, width + 20, '{'),
                         Enemy(win, height / 2, width + 50, '{'),
                         Enemy(win, height / 8, width + 35, '{'),
                         Enemy(win, height / 2, width + 15, '{'),
                         Enemy(win, height / 5, width + 55, '{'),
                         Enemy(win, height / 3, width + 59, '{'),
                         Enemy(win, height / 7, width + 30, '{'),
                         Enemy(win, height / 3, width + 35, '{'),
                         Enemy(win, height / 2, width + 55, '{'),
                         Enemy(win, height / 2, width + 80, '{'),
                         Enemy(win, height / 5, width + 90, '{'),
                         Enemy(win, height / 2, width + 75, '{'),
                         Enemy(win, height / 9, width + 45, '{'),
                         Enemy(win, height / 5, width + 30, '{'),
                         Enemy(win, height / 3, width + 40, '{'),
                         Enemy(win, height / 10, width + 50, '{'),
                         Enemy(win, height / 11, width + 20, '{'),
                         Enemy(win, height / 15, width + 50, '{'),
                         Enemy(win, height / 3, width + 21, '{'),
                         Enemy(win, height / 2, width + 25, '{'),
                         Enemy(win, height / 5, width + 45, '{'),
                         Enemy(win, height / 3, width + 90, '{'),
                         Enemy(win, height / 2, width + 85, '{'),
                         Enemy(win, height / 5, width + 50, '{'),
                         Enemy(win, height / 6, width + 30, '{'),
                         Enemy(win, height / 4, width + 25, '{'),
                         Enemy(win, height / 2, width + 15, '{'),
                         Enemy(win, height / 3, width + 55, '{'),


    };
    Enemy bullets[1000];
    Player *p = new Player(win, height / 2, 5, '>');
    do {
        p->display(enemies, bullets);
        hud(height, p->lives, p->score);
        wrefresh(win);
    } while (p->getMove() != 'x' && p->lives);
    mvprintw(height + 1, 0, "Game Over\n by Junius");
    refresh();
    int c = getch();
    (void)c;
    endwin();
    return 0;
}