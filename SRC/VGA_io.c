//--------------------------------------------------------------
// File     : VGA_io.c
//--------------------------------------------------------------

#include "VGA_io.h"
#include <stdio.h>
#include <stdlib.h>

// Level of debugging:
#define PRINT_ERROR
#define PRINT_WARNING
#define PRINT_NOTE

typedef enum { false, true } bool;

/**
 * Logger: Print functie naam, error type en meegegeven message bij een error
 * @param function de naam van de functie waarin de logger is aangeroepen
 * @param error type van de error (error, warning of note)
 * @param message de meegegeven boodschap
 */
void logger( const char* function, errorType error, const char* message ) {

    char* errortype;
    const char* functie;

    functie = function; 

    // (error)message type:
    switch (error) {
        case ERROR:
            #if !defined(PRINT_ERROR) 
                return;
            #endif
                        
            errortype = "ERROR:  ";
            break;

        case WARNING:
            #if !defined(PRINT_WARNING) 
                return;
            #endif
            
            errortype = "WARNING:";
            break;

        case NOTE:
            #if !defined(PRINT_NOTE) 
                return;
            #endif

            errortype = "NOTE:   ";
            break;
    }   

    printf("%s In functie %s: %s \n", errortype, functie, message);

}

/**
 * initialiseer_VGA: het initialiseren van het VGA scherm
 */
void initaliseer_VGA() {

    bool connected = 1;
    bool message_send = 0;

    // check VGA connection
    logger( __func__, NOTE, "Check VGA aansluiting"); 
       

    do {
        // check connection
        
        //here........... TODO

        // print error once
        if (!connected && !message_send) {   
            logger( __func__, ERROR,    "VGA is niet aangesloten, sluit VGA scherm aan."); 
            message_send = 1;
            exit(0); //TODO: remove
          
        }

        
    } while (!connected);

    logger( __func__, NOTE, "VGA is aangesloten");

    clearscherm (ZWART);

}

