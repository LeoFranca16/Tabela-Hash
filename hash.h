#include <stdlib.h>
#ifndef HASH_H
#define HASH_H
#define TRUE 1
#define FALSE 0
#define MAX 65530


struct hash *hashTable = NULL;
int eleCount = MAX;
 
struct node {
    int key;
    char name[100];
    struct node *next;
};
 
struct hash {
    struct node *head;
    int count;
};


int hash(char *key);

struct node * newNode(int key, char *name);

void insertNode(int key, char *name);

void searchNode(int key);

void deleteNode(int key);

void imprimeHash();

int palavraDiferente();

int contHash(int key);

int valorString(char *str);

int chave(int key);

#endif
