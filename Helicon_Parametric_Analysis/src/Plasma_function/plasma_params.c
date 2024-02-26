/*This file cointains the functions to obtain the main wave and plasma 
characteristics functions*/

#include "plasma_params.h"


//Plasma frequency 
//Receives:plasma density(n)
double w_p(double n){
    double wp = (n*pow(e,2))/(eps_0*m_e);
    return sqrt(wp);	
}


//Skin number of the Helicon wave
//Receives: plasma frequency (w)
double k_s(double wp){	
    return wp/c;
}


//Cyclotron frequency
//Receives: external magnetic field (B)
double w_c(double B){
    return (e*B)/(c*m_e);
}


//Helicon Wave Number
//Receives: Skin wave number(k_s), Damping factor (d)
double k_w(double ks, double d){
    return sqrt(d)*ks;
}


//Damping factor
//Receives: Wave frequency(w), cyclotron frequency(wc), collision frequency(v)
double delt(double f_0, double wc, double v){
    return (2*pi*f_0)/wc;
}


//K_min
//Receives: Damping factor(d), Skin number(k)
double k_min(double d, double ks){
    return 2*d*ks;
}


//K_max
//Receives: Damping factor(d), Skin number(k)
double k_max(double d, double ks){
    return sqrt(d/(1-d))*ks;
}


//Eigenvalue beta for H and TG waves
//Receives: Helicon wave number (K_w), wave number(k), damping factor(delt) and wave type
//H mode = 0; TG mode = 1;
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


void parametric_K(double k[], double d, double ks, double b[], int m){
    
    for(int i = 0; i <= m; i++){    
        k[i] = (d/b[i])*( pow(b[i],2) + pow(ks,2) );        
    }
}

