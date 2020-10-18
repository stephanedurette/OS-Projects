#include <unistd.h>
#include <stdio.h>
#define MAX_ARGS 5

/*  LAB3 execvp-launcher.c 
*   This program launches the L3exe program using the execl function.
*   The execl function is a member of the exec function family. It replaces the
*   the current process image with a new process image. 
*   
*   For arguments it takes in the file to be executed from PATH, or the path to what file to execute and
*   an argv array of character pointers that are Null terminated.
*   The execvp() function is a great choice when the number of command line arguments you wish
*   to pass is variable or large and you wish to seach the PATH for the program. However, program enviroment
*   variable cannot be passed this way. 
*
*   Nolan Thomas & Stephane Durrette
*   October 18, 2020
*/


int main(int argc, char *argv[]){

    //added program to path directory /usr/local/bin
    char *path = "L3exe";

    //char* fileLocation,char *args
    execvp(path, argv);

    printf("\nLauncher Complete: Error Must have occured calling new executable!\n"); //Never prints unless execl fails

    return 0;
}