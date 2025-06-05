#include <stdio.h>
#include "yuutil.h"

void println(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n"); 
}