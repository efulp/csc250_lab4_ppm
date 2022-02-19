/**
 * @author Nirre Pluf {@literal pluf@wfu.edu}
 * @date Feb. 17, 2022
 * @assignment Lab 4
 * @course CSC 250
 *
 * header files for parsing the command line arguments
 **/  

#ifndef PROC_ARGS
#define PROC_ARGS

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>


void printCommandUsage(char executable_name[]);
int processImageArgs(int argc, char *argv[], int* bitPtr, char imageFileName[]); 

#endif


