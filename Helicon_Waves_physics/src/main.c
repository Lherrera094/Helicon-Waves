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
#include "constants.h"
#include "plasma_params.h"
#include "create_folder.h"

 int main(void){
 
 	//Input values
 	double n_0 = 2.0e19;	//Plasma density [m^-3]
        double B_0 = 1.5;	//External Magnetic Field [T]
 	double w = 27.12e6; 	//Wave frequency [Hz]
 	double v = 0;		//Collision Frequency
 	
 	//Basic Parameters 
 	double wp = w_p(n_0);	//Plasma Frequency [rad/s]
 	double wc = w_c(B_0);	//Cyclotron Frequency
 	
 	//Creates folder Results
 	results_folder();
 	
 	//Creates folder to save files from run
 	plasma_files_folder();
	
	//printf("Plasma Frequency = %.10e \n", wp);
	//printf("Cyclotron Frequency = %.10e \n", wc);
	//printf("Skin Number = %.10e \n", k_s(wp));
	//printf("Wave Number = %f \n", k_w(B_0, n_0, w));
	//printf("Damping Factor = %.10e \n", delt(w, wc, v));
	 	
 	return 0;
 
 }
