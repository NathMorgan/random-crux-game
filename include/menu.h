#ifndef _MENU_H_
#define _MENU_H_

/**
 * Init Game Menu
 */
void initMenu();

/**
 * Draw Game Menu on tick
 */
void drawMenu();

/**
 * Draw menu item
 * 
 * @param name 
 * @param menuPosition 
 * @param currentPosition 
 */
void drawMenuItem(const char *name, int menuPosition, int currentPosition);

/**
 * Destroy game menu
 */
void destroyMenu();

/**
 * Init game menu textures
 */
void initMenuTextures();

/**
 * Destroy game menu textures
 */
void destroyMenuTextures();

#endif