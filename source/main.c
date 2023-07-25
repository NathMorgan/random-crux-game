#include <grrlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <ogc/pad.h>
#include "general.h"

#include "StateManager.h"

void mainChangeState(GameState newState) {
    sendDebugMessage("Custom changeState called! New state: %d\n", newState);
}

int main(void) {
    GRRLIB_Init();
    GRRLIB_Settings.antialias = false;
    PAD_Init();

    setCurrentStateFunction(mainChangeState);
    setCurrentState(STATE_MENU);

    sendDebugMessage("Debug Start");

    while (getCurrentState() != STATE_EXIT) {
        PAD_ScanPads();

        updateState();
        drawState();

        GRRLIB_Render();
    }

    sendDebugMessage("Debug End");

    // Free some textures
    GRRLIB_Exit();
    exit(0);
}