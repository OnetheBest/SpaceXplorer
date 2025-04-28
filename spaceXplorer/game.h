#ifndef GAME_H
#define GAME_H

#include "entity.h"
#include <time.h>
#include <stdlib.h>




void drawGrid(Player player, Enemy enemies[], int enemyCount, Collectible collectibles[], int collectibleCount, Bullet bullet);
void spawnEnemies();
void moveEnemies(Enemy enemies[], int enemyCount, Collectible collectibles[], int collectibleCount);
void depleteFuel(Player *player);
void applyDifficulty(Player *player, Difficulty difficulty,int *speed);
void spawnCollectibles(Collectible c[], int count);
void collectPowerups(Player *player,Collectible collectibles[]);

#endif