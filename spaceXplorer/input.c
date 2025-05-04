#include <conio.h>
#include <stdio.h>
#include "input.h"
#include "entity.h"

void Controller(Player *player, Bullet *bullet){
    char inp;
    if (_kbhit()) {
        inp = _getch();
        switch (inp) {
            case 'w':
                if (player->pos.y > 8) player->pos.y -= 1;
                break;
            case 's':
                if (player->pos.y < GRID_SIZE - 1) player->pos.y += 1;
                break;
            case 'a':
                if (player->pos.x > 0) player->pos.x -= 1;
                break;
            case 'd':
                if (player->pos.x < GRID_SIZE - 1) player->pos.x += 1;
                break;
            case 'e':
                if (player->hasBullet && !bullet->active)
                bullet->pos.x = player->pos.x;
                bullet->pos.y = player->pos.y - 1;
                bullet->active = 1;
                player->hasBullet = 0;
                break;
        }
    }
}
