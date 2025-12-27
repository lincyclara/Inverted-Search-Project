/*
NAME : LINCY K
DATE : 15/12/2025
DESCRIPTION : Inverted Search is a text-based information retrieval system implemented in C that efficiently indexes
              and searches words across multiple text files using an inverted index technique. The system preprocesses 
              input files, extracts unique words, and stores them in a hash table where each word maps to the list of 
              files in which it appears along with its frequency. By using hashing combined with linked lists, the 
              project enables fast search operations without scanning files repeatedly. It supports core functionalities
              such as database creation, word searching, displaying indexed data, saving the database to a backup file, 
              and updating the index dynamically by adding new files. This project demonstrates effective use of data 
              structures, file handling, and dynamic memory management to build a scalable and optimized search system 
              similar to those used in real-world search engines.
*/

#include "head.h"

int main(int argc , char *argv[]){

    if(argc < 2){
        printf("Use correct format:\n");
        printf(" ./a.out <filename1> <filename2> <filename3>....\n");
        return FAILURE;
    }
    file_list *fp = NULL; /*Initializing file pointer as null*/

    Hash_t Hash_table[HASH_SIZE];
    for(int i=0;i<HASH_SIZE;i++){
        Hash_table[i].link = NULL;
    }

    for(int i=1;i<argc;i++){

        if(validate(argv[i],&fp) == FAILURE ){
            return FAILURE;
        }

    }
    //printf("All files are valid\n");
    int choice;
    //char filename[30];

    while(1){
        printf("----OPERATIONS----\n");
        printf("1. Create Database\n2. Search Database\n3. Save Database\n4. Display Database\n5. Update Database\n6. Exit\n");
        scanf("%d",&choice);
        getchar();

        switch(choice){
            case 1:
                if(create(Hash_table,fp) == SUCCESS){
                    printf("Database created successfully\n");
                }
                else{
                    printf("Database creation not successful\n");
                }
                break;

            case 2:
                if(search(Hash_table) == SUCCESS){
                    printf("Word found\n");
                }
                else{
                    printf("Word not found\n");
                }
                break;

            case 3:
                if(save(Hash_table) == SUCCESS){
                    printf("Database saved successfully\n");
                }
                else{
                    printf("Database saving unsuccessful\n");
                }
                break;

            case 4:
                display(Hash_table);
                break;

            case 5:
            if(update(Hash_table,fp) == SUCCESS){
                printf("Database updated successfully\n");
            }
            else{
                printf("Database updation not successful\n");
            }
            break;

            case 6:
            printf("Exiting....\n");
            return SUCCESS;

            default:
            printf("Invalid choice\n");
            break;
        }

    }

    return SUCCESS;
}

int validate(char *filename, file_list **f_head){
    
    char *extn = strchr(filename,'.');
    if(extn == NULL || strcmp(extn,".txt") != 0){
        printf("It is not a .txt file\n");
        return FAILURE;
    }
    FILE *fp = fopen(filename,"r");
    if(fp == NULL){
        return FAILURE; /*file doesn't exit*/
    }
    fseek(fp,0,SEEK_END);
    if(ftell(fp) == 0){
        fclose(fp);
        return FAILURE; /*File empty*/
    }
    fseek(fp,0,SEEK_SET); /*move it into first position*/
    fclose(fp);

    /*Checking whether the file name is present or not*/
    file_list *temp = *f_head;
    while(temp){
        if(strcmp(temp->filename,filename) == 0){
            printf("File already exist\n");
            return FAILURE;
        }
        temp = temp->link;
    }

    /*Insert filename into the file list*/
    file_list *new = malloc(sizeof(file_list));
    if(new == NULL){
        return FAILURE;
    }
    strcpy(new->filename,filename);
    new->link = *f_head;
    *f_head = new;
    return SUCCESS;
}