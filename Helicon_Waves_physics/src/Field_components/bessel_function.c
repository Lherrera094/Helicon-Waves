/*File contains the bessel function used for the field components of the wave*/

#include "bessel_function.h"

double J_m(int m, double x){
    
    //printf("%.5f",x)
    //double J = 0;
    //for(int n = 0; n < 30; n++){
        //J += ( pow(-1, n)/( fact(n)*fact(n+m) ) )*( pow(x/2, (2*n)+m) );
    //}
    
    return J;
}




//Computes the factorial of number n
int fact(int n){
  
    int f = n;
    
    if(n == 0){
        f = 1;
    }else{
        for(int i = 1; i < n; i++){
        f = f*i;
        }
    }
    return f;
}


