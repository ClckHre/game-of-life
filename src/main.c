// Copyright (C) 2026 ClckHre
// License: GPL-3.0-or-later

#include <stdbool.h>
#include <ncurses.h>
#include "life.h"

int main() {
    int width = 16;
    int height = 16;
    int offset_x = 4;
    int offset_y = 1;
    bool grid[width*height];
    for (int i = 0; i < width*height; i++) {
        grid[i] = 0;
    }

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    mousemask(BUTTON1_CLICKED | REPORT_MOUSE_POSITION, NULL);



    MEVENT event;

    while (1) {

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (grid[x + y * height] == true) {
                    mvaddch(y + offset_y, 2 * x + offset_x, '#');
                } else {
                    mvaddch(y + offset_y, 2 * x + offset_x, '.');
                }
            }
        }

        int ch = getch();

        if (ch == KEY_MOUSE) {
            if (getmouse(&event) == OK) {
                grid[(event.x - offset_x)/2 + (event.y - offset_y) * height] = !grid[(event.x - offset_x)/2 + (event.y - offset_y) * height];
            }
        }
        if (ch == 'q') {
            break;
        }
        if (ch == ' ') {
            update_grid(grid, width, height);
        }
    }
    endwin();
    return 0;
}