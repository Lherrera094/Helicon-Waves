/* This source code contains the functions to write files 
that will save the information of the plasma parameters, simulations and 
values for the plots*/

#ifndef WRITE_FILE_H

#define WRITE_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "omp.h"
#include "constants.h"


//Functions that save in files the results of the runs and simulations
void write_plasma_params(double iv[], double pp[], double wc[], char* foldername); //Write main plasma and wave parameters in a .txt file
void write_fields_values(double (*B1)[4], double (*B2)[4], double (*E1)[4], double (*E2)[4], int size, char* foldername);
void write_parametric_K(double k[], double beta[], int m, char* foldername);


#endif
