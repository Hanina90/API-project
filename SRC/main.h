//--------------------------------------------------------------
// File     : main.h
//--------------------------------------------------------------

#ifndef MAIN_H_   
#define MAIN_H_ 

// Libs
#include <string.h>
#include <stdio.h> 

// Include API
#include "VGA_draw.h"
#include "VGA_io.h"

/** commandType. */
typedef enum {
    NONE,
    LIJN,
    ELLIPSE,
    RECHTHOEK,
    DRIEHOEK,
    TEKST,
    BITMAP,
    WACHT 

} commandType;

// Include demo app
#include "front_layer.h"
#include "logic_layer.h"
#include "io_layer.h"




#endif // MAIN_H_

