#ifndef MENU_STATE_H
#define MENU_STATE_H

/**
 * 
 */
void initMenuState();

/**
 * 
 */
void updateMenuState();

/**
 * 
 */
void drawMenuState();

/**
 * Draw menu item
 * 
 * @param name 
 * @param menuPosition 
 * @param currentPosition 
 */
void drawMenuItem(const char *name, int menuPosition, int currentPosition);

/**
 * Destroy menu objects / images
 */
void destroyMenu();

#endif