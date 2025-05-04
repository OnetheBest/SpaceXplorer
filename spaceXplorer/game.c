#include <stdio.h>
#include <windows.h>
#include "game.h"
#include "title.h"

#define kk "\x1b[30;40m"
#define ck "\x1b[36;40m"
#define rk "\x1b[31;40m"
#define rs "\x1b[0m"

void drawGrid(Player player, Enemy enemies[], int enemyCount, Collectible collectibles[], int collectibleCount, Bullet bullet) {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            int drawn = 0;
            //Draw player
            if (player.pos.x == x && player.pos.y == y) {
                printf("A");  // A = astronaut
                drawn = 1;
            }
            else {
                //Draw enemies
                for (int i = 0; i < enemyCount && !drawn; i++) {
                    if (enemies[i].spawned && enemies[i].pos.x == x && enemies[i].pos.y == y) {
                        printf("V");  // Enemy
                        drawn = 1;
                    }
                }
            //Draw bullet
                if (!drawn && bullet.active && bullet.pos.x == x && bullet.pos.y == y){
                    printf("|");
                    drawn = 1;
                }

        // Draw powerups
        for (int i = 0; i <collectibleCount && !drawn; i++) {
            if (collectibles[i].active && collectibles[i].pos.x == x && collectibles[i].pos.y == y) {
                switch (collectibles[i].type) {
                    case BULLET:
                        printf("!");
                        break;
                    case FUEL:
                        printf("+");
                        break;
                }
               drawn = 1;
            }
        }
                if (!drawn)

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



void moveEnemies(Enemy enemies[], int count, Collectible collectibles[], int collectibleCount) {
    for (int i = 0; i < count; i++) {
        if (enemies[i].spawned) {
            enemies[i].pos.y++;  // move enemy down
            if (enemies[i].pos.y >= GRID_SIZE) {
                enemies[i].pos.y = 0;  //go back to top
                enemies[i].pos.x = rand() % GRID_SIZE;
                //30% chance for collectibles to spawn
                if (rand() % 100 < 30) {
                    for (int j = 0; j < collectibleCount; j++) {
                        if (!collectibles[j].active){
                            collectibles[j].pos.x = rand() % GRID_SIZE;
                            collectibles[j].pos.y = (rand() % 10) +8;
                            collectibles[j].active = 1;
                            collectibles[j].type = rand() % 2;
                            break;
                        }
                    }
                }
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

void spawnCollectibles(Collectible c[], int count) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        c[i].pos.x = rand() % GRID_SIZE;
        c[i].pos.y = (rand() % 10) + 10;
        c[i].active = 1;
        int type = rand() % 2;
        if (type == 0)
            c[i].type = BULLET;
        else
            c[i].type = FUEL;
        c[i].lifetime = 10;
        }
}

void collectPowerups(Player *player,Collectible collectibles[]) {
    for (int i = 0; i < MAX_COLLECTIBLES; i++) {
        if (collectibles[i].active &&
            collectibles[i].pos.x == player->pos.x &&
            collectibles[i].pos.y == player->pos.y) {

            switch (collectibles[i].type) {
                case BULLET:
                    player->hasBullet = 1;  // You'll need to add this
                    break;
                case FUEL:
                    player->fuel += 20;
                    break;
            }

            collectibles[i].active = 0;
        }


    }
}

void scoreHandler(int *score, int game, int count) {
    while(game = 1) {
        score = 0;
        if (count % 1 != 0 ){
            score += 1;
        }
        count++;
    }
}