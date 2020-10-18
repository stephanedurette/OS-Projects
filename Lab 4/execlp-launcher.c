#include <unistd.h>
#include <stdio.h>

#define MAX_ARGS 5

/*  LAB3 execlp-launcher.c 
*   This program launches the L3exe program using the execlp function.
*   The execl function is a member of the exec function family. It replaces the
*   the current process image with a new process image. 
*
*   For arguments it takes in the file name which it will look for in PATH. If not in PATH the files full
*   directory path and name can also be used. The function then take in a null terminated list of arguments.
*   It is pretty much the same as execl() except for the fact that it looks for the file in PATH.
*   For that reason I would only use it in the same situations that execl is good and when the executable to be called is in PATH.
*/

int main(int argc, char* argv[]){
    //added program to path directory /usr/local/bin
    char *path = "L3exe";   //program we wish to start
    char *args[MAX_ARGS+1]; //Save space for NULL at end

    //offset by one for launcher name
    if(argc > MAX_ARGS){
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
    
    // program/program path, arg1 , arg2, . . . , argn, NULL 
    execlp( path, args[0], args[1], args[2], args[3], args[4], (char*)NULL);
    //Equivalent to calling: ./program arg1 arg2 .. argn 

    printf("\nLauncher Complete: Error Must have occured calling new executable!\n"); //Never prints unless execl fails

    return 0;
}