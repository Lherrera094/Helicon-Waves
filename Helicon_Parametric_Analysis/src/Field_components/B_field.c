/*Source file contains the calculations of the magnetic field for the 
H and TG wave*/

#include "B_field.h"

//Radial component of magnetic field
//Receives: 
double B_rComponent(double b, double T, double k, int m, double r){
    
    double Br;
    Br = ((b+k)*jn(m-1,T*r)) + ((b-k)*jn(m+1,T*r));
    return Br;
}


//Radial component of magnetic field
//Receives: 
double B_thComponent(double b, double T, double k, int m, double r){
    
    double Bth;
    Bth = ( (b+k)*jn(m-1,T*r)) - ((b-k)*jn(m+1,T*r));
    return Bth;
}


//Radial component of magnetic field
//Receives: 
double B_zComponent(double T, int m, double r){
    
    double Bz;
    Bz = -2*T*jn(m,T*r);
    return Bz;
}

double amplitud_ratio(double b[], double T[], double a, int m){
    
    double A;
    A = -(b[0]*T[0]*jn(m,T[0]*a))/(b[1]*T[1]*jn(m,T[1]*a));
    return A;

}
