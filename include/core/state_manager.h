#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "core/general.h"
#include "states/menu_state.h"
#include "states/about_state.h"
#include "states/play_state.h"
#include "states/game_over_state.h"

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