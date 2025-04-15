#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "entity.h"
#include "input.h"


void drawGrid(Player player) {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            if (player.pos.x == x && player.pos.y == y)
                printf("A");  // A = astronaut
            else
                printf(".");
        }
        printf("\n");
    }
    printf("Position: (%d, %d)\n", player.pos.x, player.pos.y);
}

int main() {
    Player player = {{GRID_SIZE / 2, GRID_SIZE / 2}, 100, 100};
    char inp;
    while(1) {
        system("cls");
        drawGrid(player);
        Controller(&player);
    }
    return 0;
}
