/**
 * Author:      Luis Carlos Herrera Quesada
 * Email:       luis.herrera-quesada@igvp.uni-stuttgart.de
 * Copyright:   University of Stuttgart
 * 
 * This is a code used to understand the fundamental physics of Helicon waves 
 * and reproduce the results obtained by Donald Arnush and Francis Chen.
 *
 * Code started: 15.02.2024
 *
 * Initial release on github: 
 *
 **/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constants.h"
#include "plasma_params.h"
#include "create_folder.h"
#include "write_file.h"
#include "read_input.h"
#include "conduct_boundary.h"
#include "omp.h"


int main(void){
 	
	//Running time variables
	clock_t start, end;
	double cpu_time_used;
 	
	//Saves the time at which the program started
 	start = clock();
 	
 	//Reads the input_values.txt file, eigenvalue beta and transverse wave number arrays to save values
 	int ARRAY_SIZE = 50000;
 	double int_value[6], beta[ARRAY_SIZE], k[ARRAY_SIZE], k_boundary[ARRAY_SIZE];
 	read_input("input_values.txt", int_value);
 	char *foldername = read_foldername("input_values.txt");
 	//int_value = {n_0, B_0, f_0, a, v, m}; Array saves input values
 	
 	double dx = 0.01;
 	for(int i = 0; i <= ARRAY_SIZE; i++){
 	    beta[i] = dx;
 	    dx += 0.01;
 	}
 	
 	//Main Plasma Parameters 
 	double wp = w_p(int_value[0]);		//Plasma Frequency [rad/s]
 	double wc = w_c(int_value[1]);		//Cyclotron Frequency [rad/s]
 	double plas_par[] = {wp, wc};
 	
 	//Wave Characteristics
 	double del = delt(int_value[2], wc, int_value[4]);		//Damping Factor
 	double K_s = k_s(wp);						//Skin number
 	double K_w = k_w(K_s, del);					//Wave number
 	double K_min = k_min(del,K_s);					//k minimum
 	double K_max = k_max(del,K_s);					//k maximum
 	double wave_char[] = {K_w, K_s, K_min, K_max, del};

 	
 	parametric_K(k, del, K_s, beta, ARRAY_SIZE);

	//Computation for boundary conditions
	double dk = (K_max - K_min)/ARRAY_SIZE;
	double rhs[ARRAY_SIZE], lhs[ARRAY_SIZE];
	k_boundary[0] = K_min;
	k_boundary[ARRAY_SIZE-1] = K_max;
 	
	#pragma omp parallel for 
	{
		for(int i = 0; i<= ARRAY_SIZE-1 ; i++){
			k_boundary[i+1] = k_boundary[i] + dk;
		}
	}

 	//eigenvalue and transverse
	double b[2], T[2];
	#pragma omp parallel for
	{
		for(int j = 0; j <= ARRAY_SIZE-1; j++){
			eigenbeta_value(K_w, k_boundary[j], del, b);
			transverse_T(b, k_boundary[j], T);
			lhs[j] = left_hand_side(b[0], k_boundary[j], int_value[3], T[0], int_value[5]);
			rhs[j] = right_hand_side(b, k_boundary[j], int_value[3], T, int_value[5]);
		}
	}
 	
 	//Creates folder RESULTS and run folder
 	results_folder();
 	plasma_files_folder(foldername);
 	
 	//Writes file with plasma parameters
 	write_plasma_params(int_value, plas_par, wave_char, foldername);
 	write_parametric_K(k, beta, ARRAY_SIZE, foldername);
	write_eigenvalues_K(rhs, lhs, k_boundary, ARRAY_SIZE, foldername);

 		
	//Saves the time at which the process ended
	end = clock();
	cpu_time_used = ( (double)(end-start) )/CLOCKS_PER_SEC;
	printf("Program Running Time = %.2e s.\n", cpu_time_used);
	
 	return 0;
 
}
