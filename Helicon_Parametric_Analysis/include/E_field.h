/*Computation of electric field for H and TG wave*/

#ifndef E_FIELD_H

#define E_FIELD_H

#include <stdio.h>
#include "constants.h"
#include <math.h>

double E_zComponent(double w, double n, double beta, double Bz);
double E_zPrimeComponent(double A, double f_0, double n, double k, double T, double beta, int m, double r);
double E_rComponent(double f_0, double k, double Bth, double E_zPrime);
double E_thComponent(double f_0, double k, int m, double Br, double Ez, double r);

#endif
