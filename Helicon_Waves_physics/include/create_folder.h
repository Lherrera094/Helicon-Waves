/*This file cointains the functions to create and check that the different folders
necessary for the code are created*/

#ifndef CREATE_FOLDERS_H

#define CREATE_FOLDERS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

//Creates the folder Results, where all outputs from runs are saved.
void results_folder(void);
void plasma_files_folder(char *foldername);


#endif
