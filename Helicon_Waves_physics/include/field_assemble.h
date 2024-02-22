/*The source code is in charge of invoke the functions from the B and E fields files, 
computes their value and save it in an array to save it in a .csv file*/

#ifndef FIELD_ASSEMBLE_H

#define FIELD_ASSEMBLE_H

#define SIZE 10000
 
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "B_field.h"
#include "E_field.h"
#include "omp.h"
#include "write_file.h"

void field_assembling(double b[], double T[], double int_value[], char *foldername);


#endif
