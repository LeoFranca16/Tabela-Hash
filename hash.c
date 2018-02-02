#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>


struct node * newNode(int key, char *name) {
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->key = key;
    strcpy(newnode->name, name);
    newnode->next = NULL;
    return newnode;
}

void insertNode(int key, char *name) {
    int hashIndex = key;
    struct node *newnode = newNode(key, name);
    if (hashTable[hashIndex].head == NULL ){
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count = 1;
        return;
    }
    newnode->next = (hashTable[hashIndex].head);
   
    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count++;
    return;
}

void searchNode(int key) {
    int hashIndex = key, flag = 0;
    struct node *myNode;
    myNode = hashTable[hashIndex].head;
    if (myNode == NULL) {
        printf("Elemento indisponivel\n");
        return;
    }
    while (myNode != NULL) {
        if (myNode->key == key) {
            printf("\nID   : [%d]\n", myNode->key);
            printf("Name : %s\n\n", myNode->name);
            flag = 1;
            break;
        }
        myNode = myNode->next;
    }
    if (!flag)
        printf("Elemento indispovivel\n");
    return;
}

void deleteNode(int key) {
    int hashIndex = key, flag = 0;
    struct node *temp, *myNode;
    myNode = hashTable[hashIndex].head;
    if (myNode == NULL) {
        printf("Dado nao existe na Hash\n");
        return;
    }
    temp = myNode;
    while (myNode != NULL) {
        if (myNode->key == key) {
            flag = 1;
            if (myNode == hashTable[hashIndex].head)
                hashTable[hashIndex].head = myNode->next;
            else
                temp->next = myNode->next;
 
            hashTable[hashIndex].count--;
            free(myNode);
            break;
        }
        temp = myNode;
        myNode = myNode->next;
    }
    if (flag)
        printf("Data deletada com sucesso\n");
    else
        printf("Data não existe na Hash\n");
    return;
}

void imprimeHash() {
    struct node *myNode;
    int i;
    int j=1;
    for (i = 0; i < eleCount; i++) {
        if (hashTable[i].count == 0)
            continue;
        myNode = hashTable[i].head;
        if (myNode == NULL)
            continue;
            while(myNode!=NULL){
        	printf("|%d| ", j++);
            printf("ID:[%d] ", myNode->key);
            printf("%s\n\n", myNode->name);
            myNode = myNode->next;
        }
    }
    return;
}

int palavraDiferente(){  //gambiarra mode ON
	struct node *myNode;
    int i;
    int cont=0;
    for (i = 0; i < eleCount; i++) {
        if (hashTable[i].count == 0)
            continue;
             myNode = hashTable[i].head;
         if (myNode == NULL)
            continue;
			cont++;
            myNode = myNode->next;  
    }
    return cont;
}

int contHash(int key){
	struct node *myNode;
    int i;
    int cont=0;
    for (i = 0; i < eleCount; i++) {
        if (hashTable[i].count == 0)
            continue;
        myNode = hashTable[i].head;    
        if (myNode == NULL)
            continue;
            while(myNode!=NULL){
            	if(myNode->key == key)
            	cont++;
            	myNode = myNode->next;

		}
    }
    return cont;
}

int valorString(char *str){
	int i, valor = 0;
	int tam = strlen(str);
	for(i=0; i<tam; i++){
		valor = 31 * valor + (int) str[i];
	}
	if(valor < 0){
		return valor * -1;
	}
	else
	return valor;
}

int chaveDiv(int key, int eleCount){
	return key % eleCount;
}
