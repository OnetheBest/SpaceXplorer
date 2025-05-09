#ifndef ENTITY_H
#define ENTITY_H

#define GRID_SIZE 18
#define MAX_ENEMIES 25
#define MAX_COLLECTIBLES 2

typedef enum {
    EASY = 1,
    NORMAL,
    HARD,
    NIGHTMARE
} Difficulty;

typedef enum {
    BULLET,
    FUEL
} Type;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int health;
    int fuel;
    int hasBullet;
} Player;

typedef struct {
    Position pos;
    int spawned;
} Enemy;

typedef struct {
    Position pos;
    int active;
    Type type;
    int lifetime;
} Collectible;

typedef struct {
    Position pos;
    int active;
} Bullet;
#endif