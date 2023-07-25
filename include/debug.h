#ifndef _DEBUG_H
#define _DEBUG_H

#include "general.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * Send debug message to console if debug is enabled
 */
void sendDebugMessage(char *message, ...);

#endif