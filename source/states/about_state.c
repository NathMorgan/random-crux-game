#include "states/about_state.h"
#include <grrlib.h>
#include <ogc/pad.h>
#include "core/state_manager.h"
#include "font_png.h"
#include "background_image_jpg.h"

typedef struct
{
    GRRLIB_texImg *background;
    GRRLIB_texImg *font;
} AboutImage;

AboutImage aboutImages;

void aboutChangeState(GameState newState) {
    sendDebugMessage("Custom changeState called! New state: %d\n", newState);
    destroyAbout();
}

void initAboutState() {
    // Init about textures
    aboutImages.background = GRRLIB_LoadTexture(background_image_jpg);
    aboutImages.font = GRRLIB_LoadTexture(font_png);

    // Init menu tileset
    GRRLIB_InitTileSet(aboutImages.font, 8, 16, 32);

    // Init state change function
    setCurrentStateFunction(aboutChangeState);
}

void updateAboutState() {
    if(PAD_ButtonsDown(0) & PAD_BUTTON_MENU) {
        setCurrentState(STATE_MENU);
    }
}

void drawAboutState() {
    GRRLIB_DrawImg(0, 0, aboutImages.background, 0, 1, 1, RGBA(255, 255, 255, 255));
    GRRLIB_Printf(32, 32, aboutImages.font, 0xFFFFFFFF, 1, "RANDOM CRUX GAME > ABOUT");
}

void destroyAbout() {
    // Clean up menu textures
    GRRLIB_FreeTexture(aboutImages.background);
    GRRLIB_FreeTexture(aboutImages.font);

    // Unset the menu state change function
    setCurrentStateFunction(false);
}