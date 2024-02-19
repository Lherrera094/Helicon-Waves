/*Source contains the functions to read the values of the input file*/


#include "read_input.h"

//Function reads the folder name in the input_values.txt
char *read_foldername(const char *filename){
    //Declares pointer to file and checks for errors
    FILE *input = fopen(filename,"r");
    
    if(input == NULL){
        printf("Error opening Input Values file. \n");
        exit(1);
    }
    
    //Variable declaration
    char *delimiter = ":";
    char *new_name;
    char *name = (char*)malloc(200 * sizeof(char));
    if( name == NULL){
        printf("String memory allocation failed. \n");
        exit(1);
    }
    
    if( fgets(name, 200, input) == NULL ){
        printf("Error reading name. \n");
        exit(1);
    }
    
    new_name = strstr(name, delimiter);
    if(new_name != NULL){
        new_name += strlen(delimiter)+1;
    }
    
    return new_name;
}



//Function reads the numerical values in the input_values.txt
void read_input(const char *filename, double input_val[]){
    
    //Declares pointer to file and checks for errors
    FILE *input = fopen(filename,"r");
    
    if(input == NULL){
        printf("Error opening Input Values file. \n");
        exit(1);
    }
    
    char name[200];
    double value;
    
    //Skip first line
    fscanf(input, "%*[^\n]\n");
    
    for(int i = 0; i < 7; i++){
        if( fscanf(input, "%s = %lf", name, &value) !=2 ){
            printf("Error accessing the values. \n");
            exit(1);
        }
        input_val[i] = value;
    }
    
    fclose(input);
}
