#include "MenuState.h"
#include <grrlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <ogc/pad.h>
#include "general.h"
#include "StateManager.h"

// Meda Files
#include "font_png.h"
#include "background_image_jpg.h"
#include "background_tuqiri_png.h"
#include "bg_png.h"
#include "bg_test_png.h"

typedef struct
{
    GRRLIB_texImg *background;
    GRRLIB_texImg *backgroundTuqiri;
    GRRLIB_texImg *font;
} MenuImage;

typedef struct {
    int id;
    char name[50];
    int state;
} MenuItem;

MenuImage menuImages;
const MenuItem menuItems[3] ={
    {1, "START", STATE_PLAY},
    {2, "HELP", STATE_HELP},
    {3, "INFO", STATE_ABOUT},
};

int selectedMenuItem = 1;
int numMenuItems;

void initMenuState() {
    const int numMenuItems = sizeof(menuItems) / sizeof(MenuItem);

    // Init menu textures
    menuImages.background = GRRLIB_LoadTexture(background_image_jpg);
    menuImages.backgroundTuqiri = GRRLIB_LoadTexturePNG(background_tuqiri_png);
    menuImages.font = GRRLIB_LoadTexture(font_png);

    // Init menu tileset
    GRRLIB_InitTileSet(menuImages.font, 8, 16, 32);
}

void updateMenuState() {
    if(PAD_ButtonsDown(0) & PAD_BUTTON_DOWN) {
        if (selectedMenuItem != numMenuItems) {
            selectedMenuItem++;
        }
    } else if (PAD_ButtonsDown(0) & PAD_BUTTON_UP) {
        if (selectedMenuItem > 1) {
            selectedMenuItem--;
        }
    }
}

void drawMenuState() {
    GRRLIB_DrawImg(0, 0, menuImages.background, 0, 1, 1, RGBA(255, 255, 255, 255));
    GRRLIB_DrawImg(150, 0, menuImages.backgroundTuqiri, 0, 1, 1, 0xFFFFFFFF);
    GRRLIB_Printf(32, 32, menuImages.font, 0xFFFFFFFF, 1, "RANDOM CRUX GAME");

    sendDebugMessage("Test: %i", numMenuItems);

    for (int i = 0; i < 3; i++) {
        drawMenuItem(menuItems[i].name, menuItems[i].id, selectedMenuItem);
    }
}

void drawMenuItem(const char *name, int menuPosition, int currentPosition) {
    u32 colour = 0xFFFFFFFF;

    if (menuPosition == currentPosition) {
        colour = RGBA(0, 0, 204, 255);
    }

    GRRLIB_Printf(32, 100 + (menuPosition * 40), menuImages.font, colour, 1, name);
}