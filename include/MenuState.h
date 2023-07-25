#ifndef MENUSTATE_H
#define MENUSTATE_H

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

#endif