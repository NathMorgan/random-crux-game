#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "general.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <ogc/pad.h>

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