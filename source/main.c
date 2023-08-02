#include <grrlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <ogc/pad.h>
#include "general.h"

int main(void) {
    GRRLIB_Init();
    GRRLIB_Settings.antialias = false;
    PAD_Init();
    
    setCurrentState(STATE_MENU);

    sendDebugMessage("Debug Start");

    while (getCurrentState() != STATE_EXIT) {
        PAD_ScanPads();

        updateState();
        drawState();

        GRRLIB_Render();
        printHeapInfo();
    }

    sendDebugMessage("Debug End");

    // Free some textures
    GRRLIB_Exit();
    exit(0);
}

void printHeapInfo() {
    struct mallinfo mi = mallinfo();

    printf("Total non-mmapped bytes (arena):       %d\n", mi.arena);
    printf("# of free chunks (ordblks):            %d\n", mi.ordblks);
    printf("# of free fastbin blocks (smblks):     %d\n", mi.smblks);
    printf("# of mapped regions (hblks):           %d\n", mi.hblks);
    printf("Bytes in mapped regions (hblkhd):      %d\n", mi.hblkhd);
    printf("Max. total allocated space (usmblks):  %d\n", mi.usmblks);
    printf("Free bytes held in fastbins (fsmblks): %d\n", mi.fsmblks);
    printf("Total allocated space (uordblks):      %d\n", mi.uordblks);
    printf("Total free space (fordblks):           %d\n", mi.fordblks);
    printf("Topmost releasable block (keepcost):   %d\n", mi.keepcost);
}