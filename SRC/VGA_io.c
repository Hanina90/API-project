//--------------------------------------------------------------
// File     : VGA_io.c
//--------------------------------------------------------------

#include "VGA_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @Brief: Zet printen aan/uit voor verschillende error types
 *
 * @param errors printen ON/OFF
 * @param warnings printen ON/OFF
 * @param notes printen ON/OFF
 */
void init_logger( bool errorON, bool warningON, bool noteON ) {

    print_error     = errorON;
    print_warning   = warningON;
    print_note      = noteON;
    
}

/**
 * @Brief: Print functie naam, error type en meegegeven message bij een error
 *
 * @param function de naam van de functie waarin de logger is aangeroepen
 * @param error type van de error (error, warning of note)
 * @param message de meegegeven boodschap
 */
void logger( const char* function, errorType error, const char* message ) {

    char* errortype;
    const char* functie;
    char output_string[128];

    functie = function; 

    // (error)message type:
    switch (error) {
        case ERROR:
            if(!print_error) return;
                        
            errortype = "ERROR:  ";
            break;

        case WARNING:
            if(!print_warning) return;
        
            errortype = "WARNING:";
            break;

        case NOTE:
            if(!print_note) return;

            errortype = "NOTE:   ";
            break;
    }   

    strcpy(output_string, errortype);
    strcat(output_string, " In functie ");
    strcat(output_string, functie);
    strcat(output_string, ": ");
    strcat(output_string, message);
    strcat(output_string, "\n");

    //UART_puts(output_string);
    printf("%s", output_string);
    
}

/**
 * @brief: het initialiseren van het VGA scherm
 */
void initaliseer_VGA() {

    bool connected = true; // TODO not implemented yet so hardcoded true
    bool message_send = false;

    // check VGA connection
    logger( __func__, NOTE, "Check VGA aansluiting"); 
       

    do {
        // check connection
        
        //here........... TODO

        // print error once
        if (!connected && !message_send) {   
            logger( __func__, ERROR,    "VGA is niet aangesloten, sluit VGA scherm aan."); 
            message_send = true;
            exit(0); //TODO: remove
          
        }
 
    } while (!connected);

    logger( __func__, NOTE, "VGA is aangesloten");
    clearscherm (ZWART); 

}

