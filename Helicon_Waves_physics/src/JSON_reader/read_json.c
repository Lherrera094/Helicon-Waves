/*This files contains the functions to read a the JSON file with the input values*/

#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>


double read_input_numJSON(){

    FILE *json = fopen("input_values.json","r");
    if(json == NULL){
        printf("Failed to open JSON file. \n");
    }
    
    
    
}

char* read_input_filenameJSON(){

    FILE *json = fopen("input_values.json","r");
    if(json == NULL){
        printf("Failed to open JSON file. \n");
    }
    
    
    
}
