#ifndef ENTITY_H
#define ENTITY_H

#define GRID_SIZE 24
#define MAX_ENEMIES 8

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int health;
    int fuel;
} Player;

typedef struct {
    Position pos;
    int spawned;
} Enemy;
#endif