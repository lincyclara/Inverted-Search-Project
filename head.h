#ifndef HEAD_H
#define HEAD_H

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1
#define HASH_SIZE 27

/*File list*/
typedef struct files{
    char filename[30];
    struct files* link;
}file_list;

/*Sub node*/
typedef struct nodeS{
    char filename[30];
    int word_count;
    struct nodeS* link;
}Sub_node;

/*Main node*/
typedef struct nodeM{
    char word[30];
    int file_count;
    Sub_node* sub_link;
    struct nodeM* link;
}Main_node;

/*Hash table*/
typedef struct hash{
    int index;
    Main_node* link;
}Hash_t;

int validate(char *, file_list **);
int create(Hash_t *Hash_table , file_list *head);
int hash_function(char *word);
int update(Hash_t *Hash_table , file_list *head);
void display(Hash_t *Hash_table );
int save(Hash_t *Hash_table );
int search(Hash_t *Hash_table);


#endif
