#include "front_layer.h"

char test_input[40] = "lijn,1,1,100,100,4,bruin";

/*
 * @brief   Print command (NOTE: wordt alleen gebruikt voor debug)
 */
void printCommand () {

    char *given_command, *given_color;
    logger (__func__, NOTE, "Print command");

    printf( "\t ============================\n");

    switch ( user_input.command ) {
        
        case LIJN:      given_command = "LIJN";         break;
        case ELLIPSE:   given_command = "ELLIPSE";      break;
        case RECHTHOEK: given_command = "RECHTHOEK";    break;
        case DRIEHOEK:  given_command = "DRIEHOEK";     break;
        case TEKST:     given_command = "TEKST";        break;
        case BITMAP:    given_command = "BITMAP";       break;
        case WACHT:     given_command = "WACHT";        break;
        case NONE:      given_command = "NONE";         break;
        default: given_command = "Waarschijnlijk NULL";
          
    }

    printf( "\t command:\t %s\n", given_command );

    switch ( user_input.input_kleur ) {
        
        case ZWART:         given_color = "ZWART";          break;
        case BLAUW:         given_color = "BLAUW";          break;
        case LICHTBLAUW:    given_color = "LICHTBLAUW";     break;
        case GROEN:         given_color = "GROEN";          break;
        case LICHTGROEN:    given_color = "LICHTGROEN";     break;
        case CYAAN:         given_color = "CYAAN";          break;
        case LICHTCYAAN:    given_color = "LICHTCYAAN";     break;
        case ROOD:          given_color = "ROOD";           break;
        case LICHTROOD:     given_color = "LICHTROOD";      break;
        case MAGENTA:       given_color = "MAGENTA";        break;
        case LICHTMAGENTA:  given_color = "LICHTMAGENTA";   break;
        case BRUIN:         given_color = "BRUIN";          break;
        case GEEL:          given_color = "GEEL";           break;
        case GRIJS:         given_color = "GRIJS";          break;
        case WIT:           given_color = "WIT";            break;
         
    }

    printf( "\t color:\t\t %s\n", given_color );

    printf( "\t ============================\n");

    
} 

void leesBuffer () { 
 
    char* word;
    const char s[2] = ",";
    char* words[MAX_NUM_OF_WORDS] = {NULL};

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
   
    getCommand  (words[COMMAND]);
    getColor    (words);

    printCommand ();

    // input is verwerkt en het command kan afgehandeld worden
    input_afhandeling ();   
    
    
 
}

void getCommand (char* inputCommand) {

    logger (__func__, NOTE, "Verkrijgen van command");

    // Aanwezigheid van command checken 
    if (inputCommand == NULL) 
        logger (__func__, ERROR, "Geen command meegegeven");

    // Command is ingevoerd:
    if (        strcmp(inputCommand, "lijn") == 0 ||
                strcmp(inputCommand, "Lijn") == 0 ||
                strcmp(inputCommand, "LIJN") == 0 ) {
                    user_input.command = LIJN;
    }
    else if (   strcmp(inputCommand, "ellipse") == 0 ||
                strcmp(inputCommand, "Ellipse") == 0 ||
                strcmp(inputCommand, "ELLIPSE") == 0 ) {
                    user_input.command = ELLIPSE;
    }
    else if (   strcmp(inputCommand, "rechthoek") == 0 ||
                strcmp(inputCommand, "Rechthoek") == 0 ||
                strcmp(inputCommand, "RECHTHOEK") == 0 ) {
                    user_input.command = RECHTHOEK;
    }
    else if (   strcmp(inputCommand, "driehoek") == 0 ||
                strcmp(inputCommand, "Driehoek") == 0 ||
                strcmp(inputCommand, "DRIEHOEK") == 0 ) {
                    user_input.command = DRIEHOEK;
    }
    else if (   strcmp(inputCommand, "tekst") == 0 ||
                strcmp(inputCommand, "Tekst") == 0 ||
                strcmp(inputCommand, "TEKST") == 0 ) {
                    user_input.command = TEKST;
    }
    else if (   strcmp(inputCommand, "tekst") == 0 ||
                strcmp(inputCommand, "Tekst") == 0 ||
                strcmp(inputCommand, "TEKST") == 0 ) {
                    user_input.command = TEKST;
    }
    else if (   strcmp(inputCommand, "bitmap") == 0 ||
                strcmp(inputCommand, "Bitmap") == 0 ||
                strcmp(inputCommand, "BITMAP") == 0 ) {
                    user_input.command = BITMAP;
    }
    else if (   strcmp(inputCommand, "wacht") == 0 ||
                strcmp(inputCommand, "Wacht") == 0 ||
                strcmp(inputCommand, "WACHT") == 0 ) {
                    user_input.command = WACHT;
    }
    else {
        // negeer command
        logger (__func__, NOTE, "Command wordt niet herkend/ondersteund dus negeer");
        user_input.command = NONE;
    }


}

void getColor ( char** inputString) {

    unsigned char COLOR_INDEX;
    char* inputColor; 

    // bereken positie van kleur in array words
    switch ( user_input.command ) {
        
        case LIJN:      COLOR_INDEX = 6;  break;
        case ELLIPSE:   COLOR_INDEX = 5;  break;
        case RECHTHOEK: COLOR_INDEX = 5;  break;
        case DRIEHOEK:  COLOR_INDEX = 7;  break;
        case TEKST:     COLOR_INDEX = 5;  break;
    
    }

    inputColor = inputString[COLOR_INDEX];

    // Command is ingevoerd:
    if (        strcmp(inputColor, "zwart") == 0 ||
                strcmp(inputColor, "Zwart") == 0 ||
                strcmp(inputColor, "ZWART") == 0 ) {
                    user_input.input_kleur = ZWART;
    }
    else if (   strcmp(inputColor, "blauw") == 0 ||
                strcmp(inputColor, "Blauw") == 0 ||
                strcmp(inputColor, "BLAUW") == 0 ) {
                    user_input.input_kleur = BLAUW;
    }
    else if (   strcmp(inputColor, "lichtblauw") == 0 ||
                strcmp(inputColor, "Lichtblauw") == 0 ||
                strcmp(inputColor, "LICHTBLAUW") == 0 ) {
                    user_input.input_kleur = LICHTBLAUW;
    }
    else if (   strcmp(inputColor, "groen") == 0 ||
                strcmp(inputColor, "Groen") == 0 ||
                strcmp(inputColor, "GROEN") == 0 ) {
                    user_input.input_kleur = GROEN;
    }
    else if (   strcmp(inputColor, "lichtgroen") == 0 ||
                strcmp(inputColor, "Lichtgroen") == 0 ||
                strcmp(inputColor, "LICHTGROEN") == 0 ) {
                    user_input.input_kleur = LICHTGROEN;
    }
    else if (   strcmp(inputColor, "cyaan") == 0 ||
                strcmp(inputColor, "Cyaan") == 0 ||
                strcmp(inputColor, "CYAAN") == 0 ) {
                    user_input.input_kleur = CYAAN;
    }
    else if (   strcmp(inputColor, "lichtcyaan") == 0 ||
                strcmp(inputColor, "Lichtcyaan") == 0 ||
                strcmp(inputColor, "LICHTCYAAN") == 0 ) {
                    user_input.input_kleur = LICHTCYAAN;
    }
    else if (   strcmp(inputColor, "rood") == 0 ||
                strcmp(inputColor, "Rood") == 0 ||
                strcmp(inputColor, "ROOD") == 0 ) {
                    user_input.input_kleur = ROOD;
    }
    else if (   strcmp(inputColor, "lichtrood") == 0 ||
                strcmp(inputColor, "Lichtrood") == 0 ||
                strcmp(inputColor, "LICHTROOD") == 0 ) {
                    user_input.input_kleur = LICHTROOD;
    }
    else if (   strcmp(inputColor, "magenta") == 0 ||
                strcmp(inputColor, "Magenta") == 0 ||
                strcmp(inputColor, "MAGENTA") == 0 ) {
                    user_input.input_kleur = MAGENTA;
    }
    else if (   strcmp(inputColor, "lichtmagenta") == 0 ||
                strcmp(inputColor, "Lichtmagenta") == 0 ||
                strcmp(inputColor, "LICHTMAGENTA") == 0 ) {
                    user_input.input_kleur = LICHTMAGENTA;
    }
    else if (   strcmp(inputColor, "bruin") == 0 ||
                strcmp(inputColor, "Bruin") == 0 ||
                strcmp(inputColor, "BRUIN") == 0 ) {
                    user_input.input_kleur = BRUIN;
    }
    else if (   strcmp(inputColor, "geel") == 0 ||
                strcmp(inputColor, "Geel") == 0 ||
                strcmp(inputColor, "GEEL") == 0 ) {
                    user_input.input_kleur = GEEL;
    }
    else if (   strcmp(inputColor, "grijs") == 0 ||
                strcmp(inputColor, "Grijs") == 0 ||
                strcmp(inputColor, "GRIJS") == 0 ) {
                    user_input.input_kleur = GRIJS;
    }
    else if (   strcmp(inputColor, "wit") == 0 ||
                strcmp(inputColor, "Wit") == 0 ||
                strcmp(inputColor, "WIT") == 0 ) {
                    user_input.input_kleur = WIT;
    }

    else {
        // negeer command
        logger (__func__, NOTE, "Kleur wordt niet herkend/ondersteund");
    }
}



