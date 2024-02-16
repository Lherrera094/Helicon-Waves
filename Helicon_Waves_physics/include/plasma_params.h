/*This file cointains the functions to obtain the main wave and plasma 
characteristics functions*/

#ifndef PLASMA_PARAMS_H

#define PLASMA_PARAMS_H

#include "constants.h"
#include <stdio.h>


double w_p(double n);
double k_s(double w);
double w_c(double B);
double k_w(double w, double n, double B);
double delt(double w, double wc, double v);


#endif
