#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "entity.h"
#include "input.h"
#include "game.h"
#include "title.h"


Enemy enemies[MAX_ENEMIES];

int main() {

    Difficulty difficulty = titleScreen();

    spawnEnemies(enemies, MAX_ENEMIES);
    Player player = {{GRID_SIZE / 2, GRID_SIZE - 3}, 100, 100};
    int move;
    while(1) {
        srand(time(NULL));
        int xpos = rand() % 18;
        if (player.pos.y < GRID_SIZE) {system("cls");}
        drawGrid(player, enemies, MAX_ENEMIES);
        Controller(&player);
        if (move % 10 == 0) {
            moveEnemies(enemies, MAX_ENEMIES);
        }
        move++;
        Sleep(1);
    }
    return 0;
}
