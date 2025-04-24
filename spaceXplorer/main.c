#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "entity.h"
#include "input.h"

Enemy enemies[MAX_ENEMIES];

void spawnEnemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].pos.x = rand() % GRID_SIZE;
        enemies[i].pos.y = 0;
        enemies[i].spawned = 1;
    }
}

void moveEnemies(Enemy enemies[], int count) {
    for (int i = 0; i < count; i++) {
        if (enemies[i].spawned) {
            enemies[i].pos.y++;  // move enemy down
            if (enemies[i].pos.y >= GRID_SIZE) {
                enemies[i].spawned = 0;  // de-spawn if off screen
            }

        }
    }
}

void drawGrid(Player player, Enemy enemies[], int enemyCount) {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            if (player.pos.x == x && player.pos.y == y)
                printf("A");  // A = astronaut
            else {
                int isEnemy = 0;
                for (int i = 0; i < enemyCount; i++) {
                    if (enemies[i].spawned && enemies[i].pos.x == x && enemies[i].pos.y == y) {
                        printf("X");  // Enemy
                        isEnemy = 1;
                        break;
                    }
                }
                if (!isEnemy)
                    printf(".");
            }
        }
        printf("\n");
    }
    printf("Position: (%d, %d)\n", player.pos.x, player.pos.y);
}

int main() {

    spawnEnemies(enemies, MAX_ENEMIES);
    Player player = {{GRID_SIZE / 2, GRID_SIZE / 2}, 100, 100};
    char inp;
    int move;
    while(1) {
        srand(time(NULL));
        int xpos = rand() % 26;
        if (player.pos.y < GRID_SIZE) {system("cls");}
        drawGrid(player, enemies, MAX_ENEMIES);
        Controller(&player);
        if (move % 10 == 0) {
            moveEnemies(enemies, MAX_ENEMIES);
        }
        move++;
        Sleep(10);
    }
    return 0;
}
