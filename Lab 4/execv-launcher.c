#include <unistd.h>
#include <stdio.h>
#define MAX_ARGS 5

/*  LAB3 execv-launcher.c 
*   This program launches the L3exe program using the execl function.
*   The execl function is a member of the exec function family. It replaces the
*   the current process image with a new process image. 
*   
*   For arguments it takes in the file location to be executed an argv array of character
*   pointers that are Null terminated.
*   The execv() function is a great choice when the number of command line arguments you wish
*   to pass is variable or large. However, it will not search PATH for the program and does not allow
*   process environment data to be passed.
*
*   Nolan Thomas & Stephane Durrette
*   October 18, 2020
*/


int main(int argc, char *argv[]){

    char *path = "L3exe";

    //char* fileLocation,char *args
    execv(path, argv);

    printf("\nLauncher Complete: Error Must have occured calling new executable!\n"); //Never prints unless execl fails

    return 0;
}