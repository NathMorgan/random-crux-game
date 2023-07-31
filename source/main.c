#include <grrlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <ogc/pad.h>
#include "general.h"

#include "StateManager.h"

int main(void) {
    GRRLIB_Init();
    GRRLIB_Settings.antialias = false;
    PAD_Init();
    
    setCurrentState(STATE_MENU);

    sendDebugMessage("Debug Start");

    while (getCurrentState() != STATE_EXIT) {
        PAD_ScanPads();

        if(PAD_ButtonsDown(0) & PAD_BUTTON_MENU) {
            setCurrentState(STATE_MENU);
        }

        updateState();
        drawState();

        GRRLIB_Render();
    }

    sendDebugMessage("Debug End");

    // Free some textures
    GRRLIB_Exit();
    exit(0);
}