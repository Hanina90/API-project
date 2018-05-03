//--------------------------------------------------------------
// File     : VGA_draw.c
//--------------------------------------------------------------

#include "VGA_draw.h"

int width = 10; 
int height = 10;

#define MAX_LIJNDIKTE 25

/**
* Coordinaten check: checkt of de coordanten valide zijn.
* @param x x coördinaat
* @param y y coördinaat
* @param width breedte van het VGA scherm
* @param height hoogte van het VGA scherm
*/
void coordinaten_check (int x, int y, int width, int height ) {


    // X is buiten het scherm
    if ( x > width || x < 0 ) 
        logger( __func__, WARNING, "X Coördinate is buiten het scherm"); 

    // Y is buiten het scherm
    if ( y > height || x < 0 ) 
        logger( __func__, WARNING, "Y Coördinate is buiten het scherm"); 

}

/**
* Coordinaten check: checkt of de lijndikte valide is.
* @param dikte dikte van de lijn
*/
void lijndikte_check (int dikte) {
    
    if (dikte > MAX_LIJNDIKTE) {
        logger( __func__, WARNING, "gegeven lijndikte is groter dan maximum lijndikte"); 
        dikte = MAX_LIJNDIKTE;
        logger( __func__, NOTE, "lijndikte is gelijk aan maximum gemaakt"); 
    }
        
}


/**
* Lijn: tekent een lijn van een startpunt tot een eindpunt, met een meegegeven dikte
* en kleur
* @param x_start x coördinaat van startpunt 
* @param y_start y coördinaat van startpunt
* @param x_stop x coördinaat van stoppunt 
* @param y_stop y coördinaat van stoppunt
* @param dikte dikte van de lijn 
* @param kleur_type kleur van de lijn
*/
void lijn (int x_start, int y_start, int x_stop, int y_stop, int dikte, kleurType kleur) {

    // coordinaten check:
    logger( __func__, NOTE, "Check start coordinaten"); 
    coordinaten_check (x_start, y_start, width, height );

    logger( __func__, NOTE, "Check stop coordinaten"); 
    coordinaten_check (x_stop, y_stop, width, height );

    // lijndikte check:
    lijndikte_check (dikte);


}

void ellipse (int x_mp, int y_mp, int radius_x, int radius_y, kleurType kleur) {

    // coordinaten check:
    logger( __func__, NOTE, "Check center coordinaten"); 
    coordinaten_check (x_mp, x_mp, width, height );

}

void rechthoek (int x_lo, int y_lo, int x_rb, int y_rb, kleurType kleur) {

    // coordinaten check:
    logger( __func__, NOTE, "Check x_lo en y_lo coordinaten"); 
    coordinaten_check (x_lo, y_lo, width, height );

    logger( __func__, NOTE, "Check x_rb en y_rb coordinaten"); 
    coordinaten_check (x_rb, y_rb, width, height );
 
/*  
    lijn( x_lo, y_lo, x_rb, y_lo, kleur )
    lijn( x_lo, y_rb, x_rb, y_rb, kleur )
    lijn( x_lo, y_lo, x_lo, y_rb, kleur )
    lijn( x_rb, y_lo, x_rb, y_rb, kleur )
*/
}

void driehoek (int x1, int y1, int x2, int y2, int x3, int y3, kleurType kleur) {

    // coordinaten check:
    logger( __func__, NOTE, "Check x1 en y1 coordinaten"); 
    coordinaten_check (x1, y1, width, height );

    logger( __func__, NOTE, "Check x2 en y2 coordinaten"); 
    coordinaten_check (x2, y2, width, height );

    logger( __func__, NOTE, "Check x3 en y3 coordinaten"); 
    coordinaten_check (x3, y3, width, height );


/*
    lijn( x1, y1, x2, y2, kleur )
    lijn( x1, y1, x3, y3, kleur )
    lijn( x2, y2, x3, y3, kleur )
*/
}

void tekst (int x, int y, const char* tekst, fontType fontnaam, kleurType kleur, stijlType stijl) {

    // coordinaten check:
    logger( __func__, NOTE, "Check x en y coordinaten"); 
    coordinaten_check (x, y, width, height );

}

void bitmap (int nr, int x_lo, int y_lo) {

    // coordinaten check:    
    logger( __func__, NOTE, "Check x_lo en y_lo coordinaten"); 
    coordinaten_check (x_lo, y_lo, width, height );
}

void clearscherm (kleurType kleur) {

    logger( __func__, NOTE, "clearscreen.");     

}

void wacht (int msecs) {
/* 
   int i = 0;
    while( i < msecs ) {
        i++;
    }
*/
}



