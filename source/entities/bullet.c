#include "entities/bullet.h"
#include <grrlib.h>

typedef struct {
    int posX, posY;
    int directionX, directionY;
    float speed;
    int width, height;
    bool isPlayerBullet;
    bool active;
} Bullet;

Bullet bullets[MAX_BULLETS];

void initBullets() {
    for(int i = 0; i < MAX_BULLETS; ++i) {
        bullets[i].active = false;
    }
}

void addBullet(
    int posX,
    int posY,
    int width,
    int height,
    bool isPlayerBullet
) {
    for(int i = 0; i < MAX_BULLETS; ++i) {
        if(!bullets[i].active) {
            bullets[i].posX = posX;
            bullets[i].posY = posY;
            bullets[i].width = width;
            bullets[i].height = height;
            bullets[i].isPlayerBullet = isPlayerBullet;
            bullets[i].active = true;
            break;
        }
    }
}

void updateBullets() {
    for(int i = 0; i < MAX_BULLETS; ++i) {
        if(bullets[i].active) {
            // Update bullet position
            bullets[i].posY -= 10;

            // Check if bullet is off-screen
            if(bullets[i].posY < 0) {
                bullets[i].active = false;
            }
        }
    }
}

void drawBullet(Bullet* bullet) {
    if (bullet->active) {
        GRRLIB_Rectangle(bullet->posX, bullet->posY, bullet->width, bullet->height, 0xFFFFFFFF, true);
    }
}

void drawBullets() {
    for(int i = 0; i < MAX_BULLETS; ++i) {
        drawBullet(&bullets[i]);
    }
}