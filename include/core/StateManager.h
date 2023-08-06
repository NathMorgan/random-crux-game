#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "core/general.h"
#include "states/MenuState.h"
#include "states/AboutState.h"
#include "states/PlayState.h"
#include "states/GameOverState.h"

#include <stdbool.h>

typedef enum {
    STATE_MENU,
    STATE_HELP,
    STATE_INFO,
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