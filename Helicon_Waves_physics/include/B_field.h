/*Source file contains the calculations of the magnetic field for the 
H and TG wave*/

#ifndef B_FIELD_H

#define B_FIELD_H

#include <stdio.h>
#include "bessel_function.h"

double B_rComponent(double b, double T, double k, int m, double r);
double B_thComponent(double b, double T, double k, int m, double r);
double B_zComponent(double T, int m, double r);

#endif
