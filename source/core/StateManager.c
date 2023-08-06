#include "core/StateManager.h"

static GameState currentState;
static SetCurrentStateFunction setCurrentStateFunc;
static bool isLoading = false;

void setCurrentStateFunction(SetCurrentStateFunction func) {
    setCurrentStateFunc = func ;
}

void setCurrentState(GameState newState) {
    setIsLoading(true);
    currentState = newState;

    if (setCurrentStateFunc) {
        setCurrentStateFunc(newState);
    }

    initState();
    setIsLoading(false);
}

void setIsLoading(bool loading) {
    isLoading = loading;
}

GameState getCurrentState() {
    return currentState;
}

void initState() {
    switch (currentState) {
        case STATE_MENU:
            initMenuState();
            break;
        case STATE_INFO:
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
    // Do not update if isLoading is set to true
    if (isLoading) {
        return;
    }

    switch (currentState) {
        case STATE_MENU:
            updateMenuState();
            break;
        case STATE_INFO:
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
    // Do not draw if isLoading is set to true
    if (isLoading) {
        return;
    }

    switch (currentState) {
        case STATE_MENU:
            drawMenuState();
            break;
        case STATE_INFO:
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

