/*This file cointains the functions to create and check that the different folders
necessary for the code are created*/

#include "create_folder.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


//Creates the folder Results, where all outputs from runs are saved.
void results_folder(void){
    
    const char* foldername = "RESULTS";  //Folder name
    
    //Check if flder already exists
    if( access(foldername, F_OK) == -1 ){
    
    //Folder does not exist, creates the folder
        int status = mkdir(foldername,0777);
    
        if(status == 0){
            printf("Folder created Succesfully. \n");
        }
        else{
            printf("Error creating the folder! \n");
        }
    }
    else{
        //Folder already exist
        printf("Folder Results already exists. \n");
    }
}

//Creates the folder to saves all the results of a run
char* plasma_files_folder(void){
    //Folder name
    char* foldername = NULL;
    char buffer[200];
    
    
    //Ask user to input folder name
    printf("Enter folder name: \n");
    
    
    scanf("RESULTS");
    //Checks if the folder Results exists
    if( access("RESULTS", F_OK) == -1 ){
        printf("Folder does not exist. \n");
    }
    
    
    //Creates the folder nanme
    if( fgets(buffer, sizeof(buffer), stdin) ){
    	
    	//Allocate the memory for the String
    	foldername = (char*)malloc( strlen(buffer)+1 );
        if(foldername != NULL){
            
            strcpy(foldername, buffer);
        }
        else{
            printf("Error reading input. \n");
        }
    }
    
    
    //Full folder path
    char subFolderPath[200];
    sprintf(subFolderPath, "RESULTS/%s", foldername);
    
    //Checks if the subfolder exists
    if( access(subFolderPath, F_OK) == -1){
        //If does not exist, it create one
        int status = mkdir(subFolderPath, 0777);
        
        if( status != 0){
            printf("Error creating sub folder. \n");
        }
    }
    
    return foldername;
    
}


