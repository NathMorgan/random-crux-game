#include "states/play_state.h"

#define SHOOT_DELAY 1500

typedef struct
{
    GRRLIB_texImg *background;
    GRRLIB_texImg *tuqiriPlayer;
    GRRLIB_texImg *font;
} PlayImage;

PlayImage playImages;

typedef struct {
    int x;
    int y;
    bool isShooting;
} Player;

Player player;

int playerMoveMultiplier = 10;
u64 playerShootDelay = 100;
u64 current_time;

void playChangeState(GameState newState) {
    sendDebugMessage("Custom changeState called! New state: %d\n", newState);
    destroyPlay();
}

void initPlayState() {
    // Init play textures
    playImages.background = GRRLIB_LoadTexture(background_image_jpg);
    playImages.font = GRRLIB_LoadTexture(font_png);
    playImages.tuqiriPlayer = GRRLIB_LoadTexturePNG(tuqiri_player_png);

    // Init play tileset
    GRRLIB_InitTileSet(playImages.font, 8, 16, 32);

    // Init state change function
    setCurrentStateFunction(playChangeState);

    // Init bullets
    initBullets();

    // Int Player
    player.x = 50;
    player.y = 50;
    player.isShooting = false;
}

void updatePlayState() {
    if (PAD_ButtonsHeld(0) & PAD_BUTTON_UP) {
        player.y -= playerMoveMultiplier;
    }

    if (PAD_ButtonsHeld(0) & PAD_BUTTON_DOWN) {
        player.y += playerMoveMultiplier;
    }

    if (PAD_ButtonsHeld(0) & PAD_BUTTON_LEFT) {
        player.x -= playerMoveMultiplier;
    }

    if (PAD_ButtonsHeld(0) & PAD_BUTTON_RIGHT) {
        player.x += playerMoveMultiplier;
    }

    if (PAD_ButtonsHeld(0) & PAD_BUTTON_A) {
        player.isShooting = true;
    } else if (player.isShooting && !(PAD_ButtonsHeld(0) & PAD_BUTTON_A)) {
        player.isShooting = false;
    }
    
    if(PAD_ButtonsHeld(0) & PAD_BUTTON_MENU) {
        setCurrentState(STATE_MENU);
    }

    if (player.isShooting && timer(playerShootDelay, &current_time)) {
        addBullet(player.x + 15, player.y - 10, 5, 15, true);
    }

    updateBullets();
}

void drawPlayState() {
    GRRLIB_DrawImg(0, 0, playImages.background, 0, 1, 1, RGBA(255, 255, 255, 255));
    GRRLIB_Printf(32, 32, playImages.font, 0xFFFFFFFF, 1, "RANDOM CRUX GAME > Play");

    drawBullets();

    GRRLIB_DrawImg(player.x, player.y, playImages.tuqiriPlayer, 0, 1, 1, 0xFFFFFFFF);
}

void destroyPlay() {
    // Clean up play textures
    GRRLIB_FreeTexture(playImages.background);
    GRRLIB_FreeTexture(playImages.font);
    GRRLIB_FreeTexture(playImages.tuqiriPlayer);

    // Unset the play state change function
    setCurrentStateFunction(false);
}