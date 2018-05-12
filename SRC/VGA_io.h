//--------------------------------------------------------------
// File     : VGA_io.h
//--------------------------------------------------------------

#ifndef VGA_IO_H_   
#define VGA_IO_H_

#include "VGA_draw.h"

#define OFF 0
#define ON  1

typedef enum { false, true } bool;

/** errorType. */
typedef enum {
    NOTE,
    WARNING,
    ERROR
} errorType;

bool print_error;     
bool print_note;      
bool print_warning; 

/** Error handling functies */
void init_logger( bool errorON, bool warningON, bool noteON );
void init_logger();
void logger (const char* function, const errorType error, const char* message);

/** general functies */
void initaliseer_VGA();

#endif // VGA_IO_H_

