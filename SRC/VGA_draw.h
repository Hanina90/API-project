//--------------------------------------------------------------
// File     : VGA_draw.h
//--------------------------------------------------------------

#ifndef VGA_DRAW_H_   
#define VGA_DRAW_H_

#include "VGA_io.h"

#define WIDTH 1000
#define HEIGHT 500

/** kleurType. */
typedef enum {
    ZWART           = 0x00,
    BLAUW           = 0x03,
    LICHTBLAUW      = 0x73,
    GROEN           = 0x1C,
    LICHTGROEN      = 0x5C,
    CYAAN           = 0x1F,
    LICHTCYAAN      = 0x7F,
    ROOD            = 0xE0,
    LICHTROOD       = 0xE9,
    MAGENTA         = 0xE3,
    LICHTMAGENTA    = 0xE2,
    BRUIN           = 0x88,
    GEEL            = 0xFC, 
    GRIJS           = 0xE6,
    WIT             = 0xFF
} kleurType;

/** stijlType. */
typedef enum {
    STYLE,
    TWEE
} stijlType;

/** fontType. */
typedef enum {
    FONT,
    TWEEDE

} fontType;

/** Error handling functies */
void coordinaten_check (int x, int y, int width, int height );
void lijndikte_check (int dikte);

/** Draw functies */
void lijn (int x_start, int y_start, int x_stop, int y_stop, int dikte, kleurType kleur);
void ellipse (int x_mp, int y_mp, int radius_x, int radius_y, kleurType kleur);
void rechthoek (int x_lo, int y_lo, int x_rb, int y_rb, kleurType kleur);
void driehoek (int x1, int y1, int x2, int y2, int x3, int y3, kleurType kleur);
void tekst (int x, int y, const char* tekst, fontType fontnaam, kleurType kleur, stijlType stijl);
void bitmap (int nr, int x_lo, int y_lo);
void clearscherm (kleurType kleur);

/** General functies */
void wacht (int msecs);

#endif // VGA_DRAW_H_

