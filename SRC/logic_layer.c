#include "logic_layer.h"

void input_afhandeling () {
    
    kleurType kleur = ZWART;    

    logger (__func__, NOTE, "Input check");

    switch ( user_input.command ) {
        
        case LIJN:
            logger (__func__, NOTE, "Teken lijn");
            lijn (1, 1, 2, 2, 30, kleur);
            break;

        case ELLIPSE:
            logger (__func__, NOTE, "Teken ellipse");
            ellipse (1, 1, 1, 1, kleur);
            break;

        case RECHTHOEK:
            logger (__func__, NOTE, "Teken rechthoek");
            rechthoek (1, 1, 1, 1, kleur);
            break;

        case DRIEHOEK:
            logger (__func__, NOTE, "Teken driehoek");
            driehoek (1, 1, 1, 1, 1, 1, kleur);
            break;

        case TEKST:
            logger (__func__, NOTE, "Teken tekst");
            tekst (1, 1, "blah", FONT, kleur, NORMAL);
            break;

        case BITMAP:
            logger (__func__, NOTE, "Teken bitmap");
            bitmap (10, 100, 100); 
            break;

        default:
            logger (__func__, WARNING, "Geen herkenbaar command");           
    }
}

    
    
            


