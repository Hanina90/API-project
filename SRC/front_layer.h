#ifndef front_layer_H_   
#define front_layer_H_

#include "main.h"

struct user_input;

struct user_input {

    commandType command;
    int  coordinates[6];
    kleurType input_kleur; 

} user_input;

void printCommand ();
void leesBuffer ();



#endif // front_layer_H_

