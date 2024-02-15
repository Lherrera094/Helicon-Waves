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

 int main(void){
 
 	//Print the constants
 	double n = 15.0;
 	double wp = w_p(n);
	
	printf("Plasma Frequency = %.10e \n", wp);
	 	
 	return 0;
 
 }
