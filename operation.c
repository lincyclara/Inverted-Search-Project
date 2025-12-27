#include "head.h"

// Search
int search(Hash_t *Hash_table)
{
    char word[30];
    printf("Enter the word to search : ");
    scanf("%s",word);

    int index = hash_function(word);

    Main_node *temp = Hash_table[index].link;
    while(temp){
        if(strcmp(temp->word,word) == 0){
            break;
        }
        temp = temp->link;
    }

    if(temp == NULL){
        printf("%s is not found in any files\n",word);
        return FAILURE;
    }

    Sub_node *sub = temp->sub_link;
    printf("%s is found in these files:\n",word);
    while(sub){
        printf("Filename : %s\tWord Count : %d\n",sub->filename,sub->word_count);
        sub = sub->link;
    }
    return SUCCESS;
}

// Display
void display(Hash_t *Hash_table)
{
    printf("Index\tWord\tFileCount\tFilename\tWordCount\n");
    for(int i=0;i < HASH_SIZE ;i++)
    {
        Main_node *temp = Hash_table[i].link;

        Sub_node *stemp = NULL;
        if(temp == NULL){
            continue;
        }
        
        while(temp != NULL){
            printf("%d\t%s\t%d\t",i,temp->word,temp->file_count);
            stemp = temp->sub_link;

            while(stemp ){
                printf("%s\t%d\n",stemp->filename,stemp->word_count);
                stemp = stemp->link;
            }
            temp = temp->link;
        }
    }

}

// Save
int save(Hash_t *Hash_table)
{
    FILE *fp = fopen("backup.txt","w");
    if(!fp ){
        return FAILURE;
    }
    for(int i=0;i< HASH_SIZE;i++){
        Main_node *temp = Hash_table[i].link;
        if(temp == NULL){
            continue;
        }
        while( temp != NULL){
            fprintf(fp,"#%d;%s;%d;",i,temp->word,temp->file_count);
           
            Sub_node *sub = temp->sub_link;
            while(sub){
                fprintf(fp,"%s;%d;",sub->filename,sub->word_count);
                sub = sub->link;
            }
            fprintf(fp,"#\n");
            temp = temp->link;
        }
    }
    fclose(fp);

    return SUCCESS;
}