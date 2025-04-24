#include <stdio.h>
#include "game.h"
#include "title.h"


void drawGrid(Player player, Enemy enemies[], int enemyCount) {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            if (player.pos.x == x && player.pos.y == y)
                printf("A");  // A = astronaut
            else {
                int isEnemy = 0;
                for (int i = 0; i < enemyCount; i++) {
                    if (enemies[i].spawned && enemies[i].pos.x == x && enemies[i].pos.y == y) {
                        printf("V");  // Enemy
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



void spawnEnemies(Enemy enemies[MAX_ENEMIES]) {
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
                enemies[i].pos.y = 0;  //go back to top
                enemies[i].pos.x = rand() % GRID_SIZE;
            }

        }
    }
}


