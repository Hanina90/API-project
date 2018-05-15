#include "front_layer.h"

char test_input[40] = "lijn,1,1,100,100,4,rood";

void printCommand () {

    logger (__func__, NOTE, "Print command");

    printf( "\tcommand: %u\n", user_input.command );

} 

void leesBuffer () { 
 
    char* word;
    const char s[2] = ",";
    char* words[20];

    logger (__func__, NOTE, "Split buffer in woorden");
    
    // eerste woord splitten
    word = strtok(test_input, s); 

    // rest van de woorden splitten en opslaan in words[]
    int i = 0;
    while (word != NULL)
    {
        words[i++] = word;
        word = strtok (NULL, s);
    }
    
    if(words[0] == NULL) 
        logger (__func__, ERROR, "Geen command meegegeven");



        if ( strcmp(words[0], "lijn") == 0 ||
             strcmp(words[0], "Lijn") == 0 ||
             strcmp(words[0], "LIJN") == 0 )
                user_input.command = LIJN;

        /*
        case "ellipse":        // Falltrough is intentional 
        case "Ellipse":
        case "ELLIPSE":
            user_input.command = ELLIPSE;
            break;

        case "rechthoek":        // Falltrough is intentional 
        case "Rechthoek":
        case "RECHTHOEK":
            user_input.command = ELLIPSE;
            break;

        case "driehoek":        // Falltrough is intentional 
        case "Driehoek":
        case "DRIEHOEK":

        */
        //TODO de rest van commands toevoegen 
          
    printCommand ();
 
}



