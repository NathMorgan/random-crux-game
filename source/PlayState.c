#include "PlayState.h"

typedef struct
{
    GRRLIB_texImg *background;
    GRRLIB_texImg *font;
} PlayImage;

PlayImage playImages;

void playChangeState(GameState newState) {
    sendDebugMessage("Custom changeState called! New state: %d\n", newState);
    destroyPlay();
}

void initPlayState() {
    // Init play textures
    playImages.background = GRRLIB_LoadTexture(background_image_jpg);
    playImages.font = GRRLIB_LoadTexture(font_png);

    // Init play tileset
    GRRLIB_InitTileSet(playImages.font, 8, 16, 32);

    // Init state change function
    setCurrentStateFunction(playChangeState);
}

void updatePlayState() {
    if(PAD_ButtonsDown(0) & PAD_BUTTON_MENU) {
        setCurrentState(STATE_MENU);
    }
}

void drawPlayState() {
    GRRLIB_DrawImg(0, 0, playImages.background, 0, 1, 1, RGBA(255, 255, 255, 255));
    GRRLIB_Printf(32, 32, playImages.font, 0xFFFFFFFF, 1, "RANDOM CRUX GAME > Play");
}

void destroyPlay() {
    // Clean up play textures
    GRRLIB_FreeTexture(playImages.background);
    GRRLIB_FreeTexture(playImages.font);

    // Unset the play state change function
    setCurrentStateFunction(false);
}