#include "states/menu_state.h"
#include <grrlib.h>
#include <ogc/pad.h>
#include "core/state_manager.h"
#include "background_image_jpg.h"
#include "background_tuqiri_png.h"
#include "font_png.h"

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
    {0, "START", STATE_PLAY},
    {1, "HELP", STATE_HELP},
    {2, "INFO", STATE_INFO}
};

int selectedMenuItemPos = 0;
const int numMenuItems = sizeof(menuItems) / sizeof(MenuItem);

void menuChangeState(GameState newState) {
    sendDebugMessage("Custom changeState called! New state: %d\n", newState);
    destroyMenu();
}

void initMenuState() {
    // Init menu textures
    menuImages.background = GRRLIB_LoadTexture(background_image_jpg);
    menuImages.backgroundTuqiri = GRRLIB_LoadTexturePNG(background_tuqiri_png);
    menuImages.font = GRRLIB_LoadTexture(font_png);

    // Init menu tileset
    GRRLIB_InitTileSet(menuImages.font, 8, 16, 32);

    // Init state change function
    setCurrentStateFunction(menuChangeState);
}

void updateMenuState() {
    if(PAD_ButtonsDown(0) & PAD_BUTTON_DOWN) {
        if (selectedMenuItemPos != numMenuItems) {
            selectedMenuItemPos++;
        }
    } else if (PAD_ButtonsDown(0) & PAD_BUTTON_UP) {
        if (selectedMenuItemPos > 0) {
            selectedMenuItemPos--;
        }
    } else if (PAD_ButtonsDown(0) & PAD_BUTTON_A) {
        const MenuItem slectedMenuItem = menuItems[selectedMenuItemPos];
        setCurrentState(slectedMenuItem.state);
    }
}

void drawMenuState() {
    GRRLIB_DrawImg(0, 0, menuImages.background, 0, 1, 1, RGBA(255, 255, 255, 255));
    GRRLIB_DrawImg(150, 0, menuImages.backgroundTuqiri, 0, 1, 1, 0xFFFFFFFF);
    GRRLIB_Printf(32, 32, menuImages.font, 0xFFFFFFFF, 1, "RANDOM CRUX GAME");

    for (int i = 0; i < numMenuItems; i++) {
        drawMenuItem(menuItems[i].name, menuItems[i].id, selectedMenuItemPos);
    }
}

void drawMenuItem(const char *name, int menuPosition, int currentPosition) {
    u32 colour = 0xFFFFFFFF;

    if (menuPosition == currentPosition) {
        colour = RGBA(0, 0, 204, 255);
    }

    GRRLIB_Printf(32, 100 + (menuPosition * 40), menuImages.font, colour, 1, name);
}

void destroyMenu() {
    // Clean up menu textures
    GRRLIB_FreeTexture(menuImages.background);
    GRRLIB_FreeTexture(menuImages.backgroundTuqiri);
    GRRLIB_FreeTexture(menuImages.font);

    // Unset the menu state change function
    setCurrentStateFunction(false);
}