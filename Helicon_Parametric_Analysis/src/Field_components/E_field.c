/*Computation of electric field for H and TG wave*/

#include "E_field.h"

double E_zComponent(double f_0, double n, double beta, double Bz){

    return -(2*pi*f_0*m_e*beta*Bz)/(n*pow(e,2)); 
}

double E_zPrimeComponent(double A, double f_0, double n, double k, double T, double beta, int m, double r){
    
    double E_zp = -((A*2*pi*f_0*m_e*beta*T)/(n*pow(e,2)))*( jn(m-1,T*r) - jn(m+1,T*r) );
    return E_zp;
}


double E_rComponent(double f_0, double k, double Bth, double E_zPrime){
    
    double Er = ((2*pi*f_0/k)*Bth) - ((1/k)*E_zPrime); 
    return Er;
}

double E_thComponent(double f_0, double k, int m, double Br, double Ez, double r){
    
    double Eth1;
    if(r == 0){
        Eth1 = 0;
    }else{
        Eth1 = (m/(k*r))*Ez; 
    }
    
    double Eth = Eth1 - ((2*pi*f_0/k)*Br); 
    return Eth;
}
