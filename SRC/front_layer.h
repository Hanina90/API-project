#ifndef front_layer_H_   
#define front_layer_H_

#include "main.h"

#define MAX_NUM_OF_WORDS 20
#define COMMAND 0

struct user_input;

struct user_input {

    commandType command;
    int         coordinates[6];
    kleurType   input_kleur; 

} user_input;

void getCommand (char* inputCommand);
void getColor   (char** inputColor);

void printCommand ();
void leesBuffer ();



#endif // front_layer_H_

