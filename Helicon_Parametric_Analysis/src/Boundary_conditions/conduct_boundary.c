/*This file contains the functions to compute the k values 
that satisfy the conducting boundary conditions*/

#include "conduct_boundary.h"


double left_hand_side(double beta, double k, double a, double T, int m){

	double lhs = ((beta+k)*jn(m,T*a)) - ((beta+k)*jn(m,T*a));
	return lhs;

}

double right_hand_side(double beta[], double k, double a, double T[], int m){

	double rhs = (((beta[1]+k)*jn(m,T[1]*a)) - ((beta[1]+k)*jn(m,T[1]*a)));
	rhs = rhs*(beta[0]*T[0]*jn(m,T[1]*a))/(beta[1]*T[1]*jn(m,T[1]*a));
	return rhs;
}