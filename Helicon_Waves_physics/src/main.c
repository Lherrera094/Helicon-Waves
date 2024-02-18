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

 int main(void){
 	
 	//Running time variables
 	clock_t start, end;
 	double cpu_time_used;
 	
 	//Saves the time at which the program started
 	start = clock();
 
 	//Input values
 	double n_0 = 2.0e19;		//Plasma density [m^-3]
        double B_0 = 0.12;		//External Magnetic Field [T]
 	double w = 27.12e6; 		//Wave frequency [Hz]
 	double v = 0;			//Collision Frequency
 	
 	double input_values[] = {n_0, B_0, w, v};	//Array saves input values
 	
 	//Main Plasma Parameters 
 	double wp = w_p(n_0);		//Plasma Frequency [rad/s]
 	double wc = w_c(B_0);		//Cyclotron Frequency [rad/s]
 	
 	double plas_par[] = {wp, wc};
 	
 	//Wave Characteristics
 	double del = delt(w, wc, v);	//Damping Factor
 	double K_s = k_s(wp);		//Skin number
 	double K_w = k_w(B_0, n_0, w);	//Wave number
 	double K_min = k_min(del,K_s);	//k minimum
 	double K_max = k_max(del,K_s);	//k maximum
 	
 	double wave_char[] = {K_w, K_s, K_min, K_max, del};
 	
 	//Creates folder Results
 	results_folder();
 	
 	//Creates folder to save files from run
 	char* foldername = plasma_files_folder();
 	
 	//Writes file with plasma parameters
 	write_plasma_params(input_values, plas_par, wave_char, foldername);
	
	/*printf("Plasma Frequency = %.3e rads/s \n", wp);
	printf("Cyclotron Frequency = %.3e rads/s\n", wc);
	printf("Skin Number = %.3e m^-1 \n", K_s);
	printf("Wave Number = %f m^-1\n", k_w(B_0, n_0, w));
	printf("Damping Factor = %.3e \n", del);
	printf("The quotient of frequencies is %f \n", wc/w);
	printf("k_min = %f m^-1 \n", k_min(del,K_s));
	printf("k_max = %f m^-1\n", k_max(del,K_s));
	*/
	
	free(foldername); 	
	
	//Saves the time at which the process ended
	end = clock();
	cpu_time_used = ( (double)(end-start) )/CLOCKS_PER_SEC;
	printf("Program Running Time = %.2e s.\n", cpu_time_used);
	//printf("%f \n", double end);
	
 	return 0;
 
 }
