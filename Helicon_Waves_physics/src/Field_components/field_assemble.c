/*The source code is in charge of invoke the functions from the B and E fields files, 
computes their value and save it in an array to save it in a .csv file*/

#include "field_assemble.h"

void field_assembling(double b[], double T[], double int_value[], char *foldername){
    
    double r;
    double A = 0.5; 						//Wave amplitude.
    double array_B1[SIZE+1][4], array_B2[SIZE+1][4];		//B array
    double dr = int_value[4]/SIZE;
    
    #pragma omp parallel for
    {
        for(int i = 0; i <= SIZE; i++){
                
            //Computation Helicon wave
            array_B1[i][0] = dr*i;
            array_B1[i][1] = B_rComponent(b[0], T[0], int_value[3], int_value[6], dr*i);
            array_B1[i][2] = B_thComponent(b[0], T[0], int_value[3], int_value[6], dr*i);
            array_B1[i][3] = B_zComponent(T[0], int_value[6], dr*i);
                
            //Computation TG wave
            array_B2[i][0] = dr*i;
            array_B2[i][1] = B_rComponent(b[1], T[1], int_value[3], int_value[6], dr*i);   
            array_B2[i][2] = B_thComponent(b[1], T[1], int_value[3], int_value[6], dr*i);
            array_B2[i][3] = B_zComponent(T[1], int_value[6], dr*i);
                
        }//end for
    }//end paralelization
        
    write_fields_values(array_B1, array_B2, SIZE, foldername);
    
}
