#include "VGA_draw.h"

int main() {

    logger (__func__, NOTE, "Start programma");

    lijn (1, 1, 2, 2, 30, ZWART);
    ellipse (1, 1, 1, 1, ZWART);
    rechthoek (1, 1, 1, 1, ZWART);
    driehoek (1, 1, 1, 1, 1, 1, ZWART);
    tekst (1, 1, "blah", FONT, ZWART, STYLE);
    bitmap (10, 100, 100); 

    return 0;
}
