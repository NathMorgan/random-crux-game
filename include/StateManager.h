#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <stdbool.h>

typedef enum {
    STATE_MENU,
    STATE_HELP,
    STATE_ABOUT,
    STATE_PLAY,
    STATE_GAME_OVER,
    STATE_EXIT
} GameState;

typedef void (*SetCurrentStateFunction)(GameState newState);

void setCurrentStateFunction(SetCurrentStateFunction func);

void setCurrentState(GameState newState);

void setIsLoading(bool loading);

GameState getCurrentState();

void initState();

void updateState();

void drawState();

#endif