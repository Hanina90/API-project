//--------------------------------------------------------------
// File     : VGA_io.h
//--------------------------------------------------------------

#ifndef VGA_IO_H_   
#define VGA_IO_H_

#include "VGA_draw.h"

/** errorType. */
typedef enum {
    ERROR,
    WARNING,
    NOTE
} errorType;

/** Error handling functies */
void logger (const char* function, const errorType error, const char* message);

/** IO functies */
void initaliseer_VGA();

#endif // VGA_IO_H_

