#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "core/state_manager.h"
#include <grrlib.h>

typedef struct {
    int x;
    int y;
    bool isShooting;
} Player;

typedef struct
{
    GRRLIB_texImg *background;
    GRRLIB_texImg *tuqiriPlayer;
    GRRLIB_texImg *font;
} PlayImage;

void playChangeState(GameState newState);

void initPlayState();

void updatePlayState();

void drawPlayState();

void destroyPlay();

#endif