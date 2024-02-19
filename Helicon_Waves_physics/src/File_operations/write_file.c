/* This source code contains the functions to write files 
that will save the information of the plasma parameters, simulations and 
values for the plots*/

#include "write_file.h"

void write_plasma_params(double iv[], double pp[], double wc[], char* foldername){
    
    char filepath[300];
    snprintf( filepath, sizeof(filepath), "RESULTS/%s%s%s", foldername, "/", "Plasma_Parameters.txt" );
    
    FILE* fptr = fopen(filepath, "w");;		//Declares and opens new file Plasma_Parameters.txt
    
    fprintf(fptr, "---------Input Values---------- \n");
    fprintf(fptr, "Plasma density (n_0) = %.2e m^-3. \n", iv[0]);
    fprintf(fptr, "External magnetic field (B_0) = %.2e T. \n", iv[1]);
    fprintf(fptr, "External wave frequency (w) = %.2e Hz. \n", iv[2]);
    fprintf(fptr, "Wave number (K) = %.2f m^-1. \n", iv[3]);
    fprintf(fptr, "Plasma radius (a) = %.3f m. \n", iv[4]);
    fprintf(fptr, "Collission frequency (v) = %.2e s^-1. \n", iv[5]);
    fprintf(fptr, "Azimuthal mode number (m) = %.1f. \n", iv[6]);
    
    fprintf(fptr, "\n---------Plasma Parameters---------- \n");
    fprintf(fptr, "Plasma frequency (W_p) = %.2e rad/s. \n", pp[0]);
    fprintf(fptr, "Cyclotron frequency (W_c) = %.2e rad/s. \n", pp[1]);
    
    fprintf(fptr, "\n---------Wave Characteristics---------\n");
    fprintf(fptr, "Wave number (K_w) = %f m^-1. \n", wc[0]);
    fprintf(fptr, "Skin number (K_s) = %.2e m^-1. \n", wc[1]);
    fprintf(fptr, "Minimum wave number (K_min) = %f m^-1. \n", wc[2]);
    fprintf(fptr, "Maximum wave number (K_max) = %f m^-1. \n", wc[3]);
    fprintf(fptr, "Damping factor (delta) = %f . \n", wc[4]);
    
    fclose(fptr);
}


void write_fields_values(void){

}


