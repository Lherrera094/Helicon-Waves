/*The source code is in charge of invoke the functions from the B and E fields files, 
computes their value and save it in an array to save it in a .csv file*/

#include "field_assemble.h"

void field_assembling(double b[], double T[], double int_value[], char *foldername){
    
    double r;
    double A1 = 1;
    double A2 = 0.5; //A1*amplitud_ratio(b, T, int_value[4], int_value[6]); 			//Wave amplitude ratio.
    double array_B1[SIZE+1][4], array_B2[SIZE+1][4]; 					//B array
    double array_E1[SIZE+1][4], array_E2[SIZE+1][4];					//E array
    double dr = int_value[4]/SIZE;
    double E_zP1[SIZE+1], E_zP2[SIZE+1];
    
    #pragma omp parallel for
    {
        for(int i = 0; i <= SIZE; i++){
                
            //Computation Helicon wave B
            array_B1[i][0] = dr*i;
            array_B1[i][1] = A1*B_rComponent(b[0], T[0], int_value[3], int_value[6], dr*i);
            array_B1[i][2] = A1*B_thComponent(b[0], T[0], int_value[3], int_value[6], dr*i);
            array_B1[i][3] = A1*B_zComponent(T[0], int_value[6], dr*i);
                
            //Computation TG wave B
            array_B2[i][0] = dr*i;
            array_B2[i][1] = A2*B_rComponent(b[1], T[1], int_value[3], int_value[6], dr*i);   
            array_B2[i][2] = A2*B_thComponent(b[1], T[1], int_value[3], int_value[6], dr*i);
            array_B2[i][3] = A2*B_zComponent(T[1], int_value[6], dr*i);
                
        }//end for
        
    }//end paralelization
    
    #pragma omp parallel for
    {
        for(int j = 0; j <= SIZE; j++){
            
            //Computation Helicon wave B
            array_E1[j][0] = dr*j;
            array_E1[j][3] = E_zComponent(int_value[2],int_value[0],b[0],array_B1[j][3]);
            E_zP1[j] = E_zPrimeComponent(A1, int_value[2],int_value[0],int_value[3],T[0],b[0],int_value[6],dr*j);
            array_E1[j][1] = E_rComponent(int_value[2],int_value[3],array_B1[j][2],E_zP1[j]);
            array_E1[j][2] = E_thComponent(int_value[2], int_value[3], int_value[6], array_B1[j][1], array_E1[j][3], dr*j);
            
                
            //Computation TG wave B
            array_E2[j][0] = dr*j;
            array_E2[j][3] = E_zComponent(int_value[2],int_value[0],b[1],array_B2[j][3]);
            E_zP2[j] = E_zPrimeComponent(A1, int_value[2],int_value[0],int_value[3],T[1],b[1],int_value[6],dr*j);
            array_E2[j][1] = E_rComponent(int_value[2],int_value[3],array_B2[j][2],E_zP2[j]);
            array_E1[j][2] = E_thComponent(int_value[2], int_value[3], int_value[6], array_B1[j][1], array_E1[j][3], dr*j);
            
        
        }
    }
    
        
    write_fields_values(array_B1, array_B2, array_E1, array_E2, SIZE, foldername);
    
}
