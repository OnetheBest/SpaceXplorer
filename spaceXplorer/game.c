#include <stdio.h>
#include <windows.h>
#include "game.h"
#include "title.h"

#define kk "\x1b[30;40m"
#define ck "\x1b[36;40m"
#define rk "\x1b[31;40m"
#define rs "\x1b[0m"

void drawGrid(Player player, Enemy enemies[], int enemyCount) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            if (player.pos.x == x && player.pos.y == y)
                printf( "A");  // A = astronaut
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

                    printf(" ");
            }
        }
        printf("\n");

    }
    printf("Position: (%d, %d)\n", player.pos.x, player.pos.y);

}

void spawnEnemies(Enemy enemies[MAX_ENEMIES], Difficulty difficulty) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].pos.x = rand() % GRID_SIZE;

        if (difficulty != NIGHTMARE) {
            enemies[i].pos.y = 0;  // anywhere
        }
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

void depleteFuel(Player *player){
    player->fuel -= 1;
}


void applyDifficulty(Player *player, Difficulty difficulty, int *speed) {
    int i;
    switch (difficulty){
        case EASY:
            player->health = 3;
            *speed = 11; //slowest
            break;
        case NORMAL:
            player->health = 2;
            *speed = 5;
            break;
        case HARD:
            player->health = 1;
            *speed = 3;
            break;
        case NIGHTMARE:
            player->health = 1;
            *speed = 3; //fastest
            break;
    }
}
