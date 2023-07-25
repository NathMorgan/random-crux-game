#include "StateManager.h"
#include "MenuState.h"
#include "AboutState.h"
#include "PlayState.h"
#include "GameOverState.h"

static GameState currentState;
static SetCurrentStateFunction setCurrentStateFunc;

void setCurrentStateFunction(SetCurrentStateFunction func) {
    setCurrentStateFunc = func;
}

void setCurrentState(GameState newState) {
    currentState = newState;
    initState();
}

GameState getCurrentState() {
    return currentState;
}

void initState() {
    switch (currentState) {
        case STATE_MENU:
            initMenuState();
            break;
        case STATE_ABOUT:
            initAboutState();
            break;
        case STATE_PLAY:
            initPlayState();
            break;
        case STATE_HELP:
            break;
        case STATE_GAME_OVER:
            initGameOverState();
            break;
        case STATE_EXIT:
            break;
    }
}

void updateState() {
    switch (currentState) {
        case STATE_MENU:
            updateMenuState();
            break;
        case STATE_ABOUT:
            updateAboutState();
            break;
        case STATE_PLAY:
            updatePlayState();
            break;
        case STATE_HELP:
            break;
        case STATE_GAME_OVER:
            updateGameOverState();
            break;
        case STATE_EXIT:
            break;
    }
}

void drawState() {
    switch (currentState) {
        case STATE_MENU:
            drawMenuState();
            break;
        case STATE_ABOUT:
            drawAboutState();
            break;
        case STATE_PLAY:
            drawPlayState();
            break;
        case STATE_HELP:
            break;
        case STATE_GAME_OVER:
            drawGameOverState();
            break;
        case STATE_EXIT:
            break;
    }
}

