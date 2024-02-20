/*Source file contains the calculations of the magnetic field for the 
H and TG wave*/

#include "B_field.h"

//Radial component of magnetic field
//Receives: 
double B_rComponent(double b, double T, double k, int m, double r){
    
    double Br;
    Br = ( ((b+k)*J_m(m-1,T*r)) + ((b-k)*J_m(m+1,T*r)) );
    
    return Br;
}


//Radial component of magnetic field
//Receives: 
double B_thComponent(double b, double T, double k, int m, double r){
    
    double Bth;
    Bth = ( ((b+k)*J_m(m-1,T*r)) - ((b-k)*J_m(m+1,T*r)) );
    
    return Bth;
}


//Radial component of magnetic field
//Receives: 
double B_zComponent(double T, int m, double r){
    
    double Bz;
    Bz = -2*T*J_m(m,T*r);
    
    return Bz;
}
