#include "debug.h"

void sendDebugMessage(char *message, ...) {
    if (DEBUG) {
        char dest[1024 * 16];
        va_list args;
        va_start(args, message);
        vsprintf(dest, message, args);
        va_end(args);
        printf(dest);
    }
}