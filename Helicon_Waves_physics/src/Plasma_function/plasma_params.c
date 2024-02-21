/*This file cointains the functions to obtain the main wave and plasma 
characteristics functions*/

#include "plasma_params.h"


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
    
    return (e*B)/(c*m_e);
     
}


//Helicon Wave Number
//Receives: external magnetic field(B), plasma density(n) and wave frequency(w)
double k_w(double k, double d){
    
    return sqrt(d)*k;
    
}


//Damping factor
//Receives: Wave frequency(w), cyclotron frequency(wc), collision frequency(v)
double delt(double w, double wc, double v){
    int i = 1;
    return ( (2*pi*w)+(i*v))/wc;
    
}


//K_min
//Receives: Damping factor(d), Skin number(k)
double k_min(double d, double k){
    return 2*d*k;
}


//K_max
//Receives: Damping factor(d), Skin number(k)
double k_max(double d, double k){
    return sqrt(d/(1-d))*k;
}


//Eigenvalue beta for H and TG waves
//Receives: Helicon wave number (K_w), wave number(k), damping factor(delt) and wave type
//H mode = 1; TG mode = 2;
void eigenbeta_value(double K_w, double K, double delta, double b[]){
    b[0] = pow(K_w,2)/K ;
    b[1] = K/delta;
}


//Transverse wave number
//Receives: H-TG eigenvalue (b)
void transverse_T(double b[], double K, double T[]){
    T[0] = sqrt( pow(b[0],2) - pow(K,2) );
    T[1] = sqrt( pow(b[1],2) - pow(K,2) );
}







