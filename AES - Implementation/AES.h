#ifndef AES_H
#define AES_H

/*
    This header file contains the definitions for 
    the structures and functions used in AES encryption.
*/

#include "string.h"

typedef unsigned char byte;

//This structure contains the necessary elements to perform AES encryption 
struct AES {
    unsigned char key[4][4];
    unsigned char expanded_key[44][4];
    unsigned char matrix_state[4][4];
};

void aes_encrypt(struct AES * aes);

//Functions used for key operations
void key_expansion(struct AES * aes);
void add_round_key(struct AES * aes, int round);

//Functions used for encrypting
void sub_bytes(struct AES * aes);
void shift_rows(struct AES * aes);
void mix_columns(struct AES * aes);
void key_schedule(byte row[4], int iter);

#endif
