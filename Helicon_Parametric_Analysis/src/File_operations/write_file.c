/* This source code contains the functions to write files 
that will save the information of the plasma parameters, simulations and 
values for the plots*/

#include "write_file.h"

void write_plasma_params(double iv[], double pp[], double wc[], char* foldername){
    
    char filepath[300];
    snprintf( filepath, sizeof(filepath), "RESULTS/%s%s%s", foldername, "/", "Plasma_Parameters.txt" );
    
    FILE* fptr = fopen(filepath, "w");;		//Declares and opens new file Plasma_Parameters.txt
    
    fprintf(fptr, "-----------------Input Values------------------ \n");
    fprintf(fptr, "Plasma density (n_0) = %.1e cm^-3. \n", iv[0]);
    fprintf(fptr, "External magnetic field (B_0) = %.0f G. \n", iv[1]);
    fprintf(fptr, "External wave frequency (w) = %.2e rad/s. \n", 2*pi*iv[2]);
    fprintf(fptr, "Plasma radius (a) = %.2f cm. \n", iv[3]);
    fprintf(fptr, "Collission frequency (\u03BD) = %.2e s^-1. \n", iv[4]);
    fprintf(fptr, "Azimuthal mode number (m) = %.1f. \n", iv[5]);
    
    fprintf(fptr, "\n---------------Plasma Parameters-------------- \n");
    fprintf(fptr, "Plasma frequency (W_p) = %.2e rad/s. \n", pp[0]);
    fprintf(fptr, "Cyclotron frequency (W_c) = %.2e rad/s. \n", pp[1]);
    
    fprintf(fptr, "\n-------------Wave Characteristics-------------\n");
    fprintf(fptr, "Wave number (K_w) = %f cm^-1. \n", wc[0]);
    fprintf(fptr, "Skin number (K_s) = %.3f cm^-1. \n", wc[1]);
    fprintf(fptr, "Minimum wave number (K_min) = %f cm^-1. \n", wc[2]);
    fprintf(fptr, "Maximum wave number (K_max) = %f cm^-1. \n", wc[3]);
    fprintf(fptr, "Damping factor (\u03B4) = %f . \n", wc[4]);
    
    fclose(fptr);
}


void write_fields_values(double (*B1)[4], double (*B2)[4], double (*E1)[4], double (*E2)[4], int size, char* foldername){

    char filepathB1[300], filepathB2[300],filepathE1[300], filepathE2[300];
    snprintf( filepathB1, sizeof(filepathB1), "RESULTS/%s%s%s", foldername, "/", "B_H_wave.csv" );
    snprintf( filepathB2, sizeof(filepathB2), "RESULTS/%s%s%s", foldername, "/", "B_TG_wave.csv" );
    snprintf( filepathE1, sizeof(filepathE1), "RESULTS/%s%s%s", foldername, "/", "E_H_wave.csv" );
    snprintf( filepathE2, sizeof(filepathE2), "RESULTS/%s%s%s", foldername, "/", "E_TG_wave.csv" );
    
    FILE* fptrB_H = fopen(filepathB1, "w");		//Declares and opens new file B_H_wave.txt
    FILE* fptrB_TG= fopen(filepathB2, "w");		//Declares and opens new file B_TG_wave.txt
    FILE* fptrE_H = fopen(filepathE1, "w");		//Declares and opens new file B_H_wave.txt
    FILE* fptrE_TG= fopen(filepathE2, "w");		//Declares and opens new file B_TG_wave.txt
    
    fprintf(fptrB_H, "r(m), B_r(T), B_theta(T), B_z(T) \n");
    fprintf(fptrB_TG, "r(m), B_r(T), B_theta(T), B_z(T) \n");
    fprintf(fptrE_H, "r(m), E_r(T), E_theta(T), E_z(T) \n");
    fprintf(fptrE_TG, "r(m), E_r(T), E_theta(T), E_z(T) \n");
    
    #pragma omp parallel for
    {
        for(int i = 0; i <= size; i++){
            
            fprintf(fptrB_H, "%.5e, %.5e, %.5e, %.5e \n", B1[i][0], B1[i][1], B1[i][2], B1[i][3]);
            fprintf(fptrB_TG, "%.5e, %.5e, %.5e, %.5e \n", B2[i][0], B2[i][1], B2[i][2], B2[i][3]);
            fprintf(fptrE_H, "%.5e, %.5e, %.5e, %.5e \n", E1[i][0], E1[i][1], E1[i][2], E1[i][3]);
            fprintf(fptrE_TG, "%.5e, %.5e, %.5e, %.5e \n", E2[i][0], E2[i][1], E2[i][2], E2[i][3]);
                
        }//end for
    }//end parallelization
    
    fclose(fptrB_H);
    fclose(fptrB_TG);
    fclose(fptrE_H);
    fclose(fptrE_TG);

}


void write_parametric_K(double k[], double beta[], int m, char* foldername){
    char filepath[300];
    snprintf( filepath, sizeof(filepath), "RESULTS/%s%s%s", foldername, "/", "Beta_k_relation.csv" );
    
    FILE* fptrKB = fopen(filepath, "w");		//Declares and opens new file K_beta.csv
    
    fprintf(fptrKB, "k, beta \n");
    
    for(int i = 0; i <= m; i++){
        fprintf(fptrKB, "%.5e, %.5e \n", k[i], beta[i]);
    }
    
    fclose(fptrKB);
}

void write_eigenvalues_K(double rhs[], double lhs[], double k[], int m, char* foldername){
    char filepath[300];
    snprintf( filepath, sizeof(filepath), "RESULTS/%s%s%s", foldername, "/", "eigenvaluesK.csv" );
    
    FILE* fptr = fopen(filepath, "w");		//Declares and opens new file K_beta.csv
    
    fprintf(fptr, "k,lhs,rhs\n");
    
    for(int i = 0; i <= m; i++){
        fprintf(fptr, "%.5e, %.5e, %.5e \n", k[i], lhs[i], rhs[i]);
    }
    
    fclose(fptr);
}


