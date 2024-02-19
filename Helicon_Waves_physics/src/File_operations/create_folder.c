/*This file cointains the functions to create and check that the different folders
necessary for the code are created*/

#include "create_folder.h"


//Creates the folder RESULTS, where all outputs from runs are saved.
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
        printf("Folder RESULTS already exists. \n");
    }
}

//Creates the folder to saves all the results of a run
void plasma_files_folder(char *foldername){
    
    //scanf("RESULTS");
    //Checks if the folder Results exists
    if( access("RESULTS", F_OK) == -1 ){
        printf("Folder does not exist. \n");
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
 
}


