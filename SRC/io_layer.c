//--------------------------------------------------------------
// File     : io_layer.c
//--------------------------------------------------------------

#include "io_layer.h"

/**
 * @brief: het initialiseren van de VGA API
 */
void init_VGA_API() {

    // initialiseer logger
    init_logger(ON, ON, ON);
    logger (__func__, NOTE, "Initialiseer VGA API");

    // initialiseer VGA scherm
    initaliseer_VGA();

}

void init_UART() {

    /* USARTx configured as follow:
      - BaudRate = 115200 baud
      - Word Length = 8 Bits
      - One Stop Bit
      - No parity
      - Hardware flow control disabled (RTS and CTS signals)
      - Receive and transmit enabled
    */

    // TODO UART_init();
    logger (__func__, NOTE, "Initialiseer UART");
}


