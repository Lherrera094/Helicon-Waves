/*This file cointains the functions to obtain the main wave and plasma 
characteristics functions*/

#ifndef PLASMA_PARAMS_H

#define PLASMA_PARAMS_H

#include "constants.h"
#include <stdio.h>
#include <math.h>


double w_p(double n);
double k_s(double w);
double w_c(double B);
double k_w(double k, double d);
double delt(double w, double wc, double v);
double k_min(double d, double k);
double k_max(double d, double k);
void eigenbeta_value(double K_w, double K, double delta, double b[]);
void transverse_T(double b[], double K, double T[]);
void parametric_K(double k[], double d, double ks, double b[], int m);

#endif
