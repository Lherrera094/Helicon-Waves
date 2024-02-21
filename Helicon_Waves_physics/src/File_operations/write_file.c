/* This source code contains the functions to write files 
that will save the information of the plasma parameters, simulations and 
values for the plots*/

#include "write_file.h"

void write_plasma_params(double iv[], double pp[], double wc[], double b[], double T[], char* foldername){
    
    char filepath[300];
    snprintf( filepath, sizeof(filepath), "RESULTS/%s%s%s", foldername, "/", "Plasma_Parameters.txt" );
    
    FILE* fptr = fopen(filepath, "w");;		//Declares and opens new file Plasma_Parameters.txt
    
    fprintf(fptr, "-----------------Input Values------------------ \n");
    fprintf(fptr, "Plasma density (n_0) = %.1e cm^-3. \n", iv[0]);
    fprintf(fptr, "External magnetic field (B_0) = %.0f G. \n", iv[1]);
    fprintf(fptr, "External wave frequency (w) = %.2e rad/s. \n", 2*pi*iv[2]);
    fprintf(fptr, "Wave number (K) = %.4f cm^-1. \n", iv[3]);
    fprintf(fptr, "Plasma radius (a) = %.2f cm. \n", iv[4]);
    fprintf(fptr, "Collission frequency (\u03BD) = %.2e s^-1. \n", iv[5]);
    fprintf(fptr, "Azimuthal mode number (m) = %.1f. \n", iv[6]);
    
    fprintf(fptr, "\n---------------Plasma Parameters-------------- \n");
    fprintf(fptr, "Plasma frequency (W_p) = %.2e rad/s. \n", pp[0]);
    fprintf(fptr, "Cyclotron frequency (W_c) = %.2e rad/s. \n", pp[1]);
    
    fprintf(fptr, "\n-------------Wave Characteristics-------------\n");
    fprintf(fptr, "Wave number (K_w) = %f cm^-1. \n", wc[0]);
    fprintf(fptr, "Skin number (K_s) = %.3f cm^-1. \n", wc[1]);
    fprintf(fptr, "Minimum wave number (K_min) = %f cm^-1. \n", wc[2]);
    fprintf(fptr, "Maximum wave number (K_max) = %f cm^-1. \n", wc[3]);
    fprintf(fptr, "Damping factor (\u03B4) = %f . \n", wc[4]);
    
    
    fprintf(fptr, "\n-----------------Helicon Wave-----------------\n");
    fprintf(fptr, "Eigenvalue (\u03B2_1) = %f cm^-1. \n", b[0]);
    fprintf(fptr, "Transverse wave number (T_1) = %f cm^-1. \n", T[0]);
    
    fprintf(fptr, "\n--------------------TG Wave-------------------\n");
    fprintf(fptr, "Eigenvalue (\u03B2_2) = %f cm^-1. \n", b[1]);
    fprintf(fptr, "Transverse wave number (T_2) = %f cm^-1. \n", T[1]);
    
    fclose(fptr);
}


void write_fields_values(double (*B1)[4], double (*B2)[4], int size, char* foldername){

    char filepath1[300], filepath2[300];
    snprintf( filepath1, sizeof(filepath1), "RESULTS/%s%s%s", foldername, "/", "B_H_wave.csv" );
    snprintf( filepath2, sizeof(filepath2), "RESULTS/%s%s%s", foldername, "/", "B_TG_wave.csv" );
    
    FILE* fptrB_H = fopen(filepath1, "w");		//Declares and opens new file B_H_wave.txt
    FILE* fptrB_TG= fopen(filepath2, "w");		//Declares and opens new file B_TG_wave.txt
    
    fprintf(fptrB_H, "r(m), B_r(T), B_theta(T), B_z(T) \n");
    fprintf(fptrB_TG, "r(m), B_r(T), B_theta(T), B_z(T) \n");
    
    #pragma omp parallel for
    {
        for(int i = 0; i <= size; i++){
            
            fprintf(fptrB_H, "%.5f, %.5f, %.5f, %.5f \n", B1[i][0], B1[i][1], B1[i][2], B1[i][3]);
            fprintf(fptrB_TG, "%.5f, %.5f, %.5f, %.5f \n", B2[i][0], B2[i][1], B2[i][2], B2[i][3]);
                
        }//end for
    }//end parallelization
    
    fclose(fptrB_H);
    fclose(fptrB_TG);

}


