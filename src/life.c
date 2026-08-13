// Copyright (C) 2026 ClckHre
// License: GPL-3.0-or-later

#include <stdbool.h>
#include "life.h"

int get_neighbour_amount(int index, bool *grid, int width, int height) {
    int amount = 0;
    for (int x = -1; x < 2; x++) {
        for (int y = -1; y < 2; y++) {
            if (index + x + y*width <= -1) continue;
            if (index + x + y*width >= width*height) continue;
            if (index % width + x <= -1) continue;
            if (index % width + x >= width) continue;
            if (x == 0 && y == 0) continue;
            if (grid[index + x + y*width] == 1) {
                amount++;
            }
        }
    }
    return amount;
}



void update_grid(bool *grid, int width, int height) {
    bool initial_grid[width*height];
    for (int i = 0; i < width*height; i++) {
        initial_grid[i] = grid[i];
    }
    int neighbour_amount = 0;
    for (int i = 0; i < width*height; i++) {
        neighbour_amount = get_neighbour_amount(i, initial_grid, width, height);
        if (neighbour_amount == 3) {
            grid[i] = true;
            continue;
        }
        if (neighbour_amount == 2) {
            continue;
        }
        grid[i] = false;
    }


}


