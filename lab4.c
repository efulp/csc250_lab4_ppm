/**
 * This program reads a PPM image file and prints the LSb encrypted message (using b bits), followed
 * by the number of characters in the message and the number of pixels used (to store the message)
 * The number of LSb used and PPM image file name is provided using command line arguments. If either
 * argument is not proveded or is incorrect, the program will exit and provide an error message.
 *
 * Note: 
 *   Requires getImageArgs.h (.c) and ppmReadWrite.h (.c)
 *
 * Compile:
 *   gcc -ansi -pedantic -Wall lab4.c getImageArgs.c ppmReadWrite.c
 *
 * @author Your Name Here {@literal <pluf@wfu.edu>}
 * @date Feb. 19, 2022
 * @assignment Lab 4
 * @course CSC 250
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppmReadWrite.h"
#include "getImageArgs.h"


int recoverMessage(struct Image *img);  
void printCharBits(unsigned char x);


int main(int argc, char *argv[]) {
    struct Image *img;
    char imageFilename[20];
    int bit;
    int argsOk;
    int fileOk;

    argsOk = processImageArgs(argc, argv, &bit, imageFilename); 
    if(!argsOk) 
        return 1;

    fileOk = readImage(&img, imageFilename);

    if(!fileOk) 
        return 1;

    recoverMessage(img); 

    if(img) free(img);  

    return 0;
}


int recoverMessage(struct Image *img) {
    unsigned char *color = (unsigned char *) img->data;  /* pointer to the RGB color components of img */

    printf("first pixel R[%d], G[%d], B[%d] \n", color[0], color[1], color[2]);
    /* let's print the bits, maybe helpful for debugging */
    printCharBits(color[0]);  
    printCharBits(color[1]);  
    printCharBits(color[2]);

    return 1;
}


/**
 * Helpful function that prints the bits of an unsigned char
 */
void printCharBits(unsigned char x) {
    int value = x;
    char *bits;
    int i;
    bits = malloc((size_t) (sizeof(x)*8 + 1));
    for(i = 0; i < sizeof(x)*8; i++) {
        bits[sizeof(x)*8 - i - 1] = (char) ((value & 0x1) + 48);
        value = value >> 1;
    }
    bits[sizeof(x)*8] = '\0';
    printf("%x(%s)\n", x, bits);
    free(bits);
}


