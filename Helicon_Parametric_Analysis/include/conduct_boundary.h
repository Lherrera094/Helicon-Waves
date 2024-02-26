/*This file contains the functions to compute the k values 
that satisfy the conducting boundary conditions*/

#ifndef CONDUCT_BOUNDARY_H

#define CONDUCT_BOUNDARY_H

#include <math.h>
#include <stdio.h>

double left_hand_side(double beta, double k, double a, double T, int m);
double right_hand_side(double beta[], double k, double a, double T[], int m);

#endif
