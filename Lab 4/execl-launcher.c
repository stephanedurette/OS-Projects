#include <unistd.h>
#include <stdio.h>
#define MAX_ARGS 5

/*  LAB3 execl-launcher.c 
*   This program launches the L3exe program using the execl function.
*   The execl function is a member of the exec function family. It replaces the
*   the current process image with a new process image. Therefore after execl is
*   called the current process is ended and the new one takes its place.
*   
*   For arguments it takes in the file location twice and then a null terminated
*   list of arguments.

*   It is a good choice for when you just want to replace current process
*   with a new one and have few cmd line variables you wish to pass. Even better if you know the exact number
*   of cmd line variables. Otherwise it is akward to pass many or an unknown amount because each arg must be passed
*   as its own variable to the function and only strings are excepted. It also does not allow for a new process enviroment
*   to be specified and will not look for the new process in PATH.
*
*   Nolan Thomas & Stephane Durrette
*   October 18, 2020
*/


int main(int argc, char *argv[]){

    char *path = "L3exe";   //program we wish to start
    char *args[MAX_ARGS+1]; //Save space for NULL at end

    if(argc> (MAX_ARGS)){
        printf("To many cmd line arguments. Max is %d\n", MAX_ARGS);
        return -1;
    }

    //We wont pass the name of the launcher as a Parameter
    int i = 0;
    while(i < argc-1){
        args[i] = argv[i+1];
        i++;
    }
    args[i] = (char*)NULL;
    
    // program, program, arg1 , arg2, . . . , argn, NULL 
    execl(path, path, args[0], args[1], args[2], args[3], args[4], (char*)NULL);
    //Equivalent to calling: ./program arg1 arg2 .. argn 

    printf("\nLauncher Complete: Error Must have occured calling new executable!\n"); //Never prints unless execl fails

    return 0;
}