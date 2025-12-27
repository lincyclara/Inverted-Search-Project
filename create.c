#include "head.h"
//create

int create(Hash_t *Hash_table , file_list *f_head)
{
    char word[30];
    file_list *fptr = f_head;

    while(fptr)
    {
        FILE *fp = fopen(fptr->filename, "r");
        if(!fp){
            fptr = fptr->link;
            continue;
        }

        while(fscanf(fp,"%s", word) != EOF)
        {

            int index = hash_function(word);

            if((Hash_table[index].link) == NULL){

                Main_node *new = malloc(sizeof(Main_node));
                if(!new){
                    return FAILURE;
                }
                strcpy(new->word,word);
                new->file_count = 1;
                new->link = NULL;

                Sub_node *sub = malloc(sizeof(Sub_node));
                if(!sub){
                    return FAILURE;
                }
                strcpy(sub->filename,fptr->filename);
                sub->word_count = 1;
                sub->link = NULL;

                new->sub_link = sub;
                Hash_table[index].link = new;
            }

            else{

                Main_node *temp = Hash_table[index].link;
                Main_node *prev = NULL;

                while(temp){
                    if(strcmp(temp->word,word) == 0){
                        break;
                    }
                    prev = temp;
                    temp = temp->link;
                }

                if(temp == NULL){
                    Main_node *new = malloc(sizeof(Main_node));
                    if(!new){
                        return FAILURE;
                    }
                    strcpy(new->word,word);
                    new->file_count = 1;
                    new->link = NULL;

                    Sub_node *sub = malloc(sizeof(Sub_node));
                    if(!sub){
                        return FAILURE;
                    }
                    strcpy(sub->filename,fptr->filename);
                    sub->word_count = 1;
                    sub->link = NULL;

                    new->sub_link = sub;
                    if(prev){
                        prev->link = new;
                    }
                    else{
                        Hash_table[index].link = new;
                    }
                    continue;
                }

                Sub_node *stemp = temp->sub_link;
                Sub_node *sprev = NULL;

                while(stemp){
                    if(strcmp(stemp->filename,fptr->filename) == 0){
                        break;
                    }
                    sprev = stemp;
                    stemp = stemp->link;
                }
                if(stemp != NULL){
                    stemp->word_count++;
                    continue;
                }
                    
                Sub_node *s1 = malloc(sizeof(Sub_node));
                if(!s1){
                    return FAILURE;
                }

                strcpy(s1->filename,fptr->filename);
                s1->word_count = 1;
                s1->link = NULL;

                if(sprev ){
                    sprev->link = s1;
                }
                else{
                    temp->sub_link = s1;
                }
                temp->file_count++;
                
            }   
        }
        fclose(fp);
        fptr = fptr->link; 
    }
    return SUCCESS;
}

int hash_function(char *word){

    char ch = word[0];
    if(ch >= 'A' && ch <= 'Z' ){
        return ch -'A';
    }
    else if(ch >= 'a' && ch <= 'z'){
        return ch - 'a';
    }
    else {
        return 26;
    }
}