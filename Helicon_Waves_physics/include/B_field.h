/*Source file contains the calculations of the magnetic field for the 
H and TG wave*/

#ifndef B_FIELD_H

#define B_FIELD_H

#include <stdio.h>
#include <math.h>

double B_rComponent(double b, double T, double k, int m, double r);
double B_thComponent(double b, double T, double k, int m, double r);
double B_zComponent(double T, int m, double r);
double amplitud_ratio(double b[], double T[], double a, int m);

#endif
