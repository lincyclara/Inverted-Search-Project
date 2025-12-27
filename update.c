#include "head.h"

// update

int update(Hash_t *Hash_table,file_list *f_head){
    char filename[30];

    FILE *fp = fopen("backup.txt","r");
    if(fp == NULL){
        return FAILURE;
    }
    char line[1000];

    while(fgets(line,sizeof(line),fp)){
        if(line[0] != '#'){
            continue;
        }

        int index, file_count;
        char word[30];

        if(sscanf(line, "#%d;%[^;];%d;",&index, word, &file_count) != 3){
            printf("Error reading the line\n");
            continue;
        }

        char *token;
        token = strtok(line, ";");
        index = atoi(token + 1);

        token = strtok(NULL,";");
        strcpy(word,token);

        token = strtok(NULL,";");
        file_count = atoi(token);

        Main_node *main_node = (Main_node*)malloc(sizeof(Main_node));
        strcpy(main_node->word, word);
        main_node->file_count = file_count;
        main_node->link = NULL;
        main_node->sublink = NULL;  // or sub_link depending on your struct

        Sub_node *last_sub = NULL;

        for (int i = 0; i < file_count; i++) {
            char fname[30];
            int count;

            token = strtok(NULL, ";"); // filename
            if (!token) break;
            strcpy(fname, token);

            token = strtok(NULL, ";"); // word count
            if (!token) break;
            count = atoi(token);

            // Create sub-node
            Sub_node *sub = (Sub_node*)malloc(sizeof(Sub_node));
            strcpy(sub->filename, fname);
            sub->word_count = count;
            sub->link = NULL;

            // Link sub-nodes
            if (main_node->sublink == NULL) {
            main_node->sublink = sub;
            last_sub = sub;
            } else {
            last_sub->link = sub;
            last_sub = sub;
        }
        if (Hash_table[index].link == NULL) {
            Hash_table[index].link = main_node;

        }
        else {
            Main_node *temp = Hash_table[index].link;
            while (temp->link != NULL){
                temp = temp->link;
            } 
        temp->link = main_node;
}

}

    }
}