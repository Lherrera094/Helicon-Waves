/*This file cointains the functions to obtain the main wave and plasma 
characteristics functions*/

#include "plasma_params.h"
#include "constants.h"
#include <math.h>


//Plasma frequency 
//Receives:plasma density(n)
double w_p(double n){

    double w = (n*pow(e,2))/(eps_0*m_e);
    return sqrt(w);
	
}


//Skin number of the Helicon wave
//Receives: plasma frequency (w)
double k_s(double w){
	
    return w/c;
	
}


//Cyclotron frequency
//Receives: external magnetic field (B)
double w_c(double B){
    
    return (e*B)/m_e;
     
}


//Wave Number
//Receives: external magnetic field(B), plasma density(n) and wave frequency(w)
double k_w(double B, double n, double w){
    
    double k = (w*n*mu_0*e)/B;
    return sqrt(k);
    
}


//Damping factor
//Receives: Wave frequency(w), cyclotron frequency(wc), collision frequency(v)
double delt(double w, double wc, double v){
    int i = 1;
    return (w+(i*v))/wc;
    
}





