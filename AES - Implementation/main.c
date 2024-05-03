//main function for the AES encryption but faster
#ifndef AES_MAIN
#define AES_MAIN

//Include header files for AES struct and input/output
#include "aes.h"
#include "stdio.h"
#include <stdlib.h>
#include <assert.h>


/*
    It first creates a struct of type AES and reads the key from standard input.
    Then it reads in blocks of data from the standard input until end of file.
    Each block of data is then encrypted using the aes_encrypt function
    from the aes.h header file and the encrypted data is output to standard output.
*/

int main(int argc, char *argv[]){
    //Create AES struct
    struct AES aes_struct;
    //Read the encryption key from stdin
    fread(aes_struct.key, 4, 4, stdin);

    //Set buffer for standard input
    setvbuf(stdin, NULL, _IOFBF, BUFSIZ);

    //Set buffer for standard output
    setvbuf(stdout, NULL, _IOFBF, BUFSIZ);

    //Read in data blocks and encrypt one until end of file
    while(!feof(stdin)){
        fread(aes_struct.matrix_state, 4, 4, stdin);

        //encrypt the data block and write the result to stdout
        if(!feof(stdin)){
            aes_encrypt(&aes_struct);
            fwrite(aes_struct.matrix_state, 4, 4, stdout);
        }
    }
    
    return 0;
}

#endif