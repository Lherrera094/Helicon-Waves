/* This source code contains the functions to write files 
that will save the information of the plasma parameters, simulations and 
values for the plots*/

#ifndef WRITE_FILE_H

#define WRITE_FILE_H


//Functions that save in files the results of the runs and simulations
void write_plasma_params(double iv[], double pp[], double wc[], char* foldername); //Write main plasma and wave parameters in a .txt file
void write_fields_values(void);


#endif
