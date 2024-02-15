/*This file cointains the functions to obtain the main wave and plasma 
characteristics functions*/

#include "plasma_params.h"
#include "constants.h"
#include <math.h>

double w_p(double n){
	
	//double w = (n + 2);
	
	return (n*pow(e,2))/(eps_0*m_e);
}
