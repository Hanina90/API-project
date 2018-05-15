#include "main.h"

int main() {


    init_VGA_API();
    init_UART();

    logger (__func__, NOTE, "Start programma");

    //input_afhandeling ();
    leesBuffer();

    return 0;
}
