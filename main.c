//Autor: Leonardo França Bessa

#include "hash.c"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>


int main(int argc, char const *argv[]){
	int op;
	int contador;
	int contp;
	int contdif;
    char name[MAX];
    hashTable = (struct hash *) calloc(MAX, sizeof(struct hash));
    
    FILE *arq;
    arq = fopen("dicionario.txt", "r");
    int key;
    
    
    while( fscanf(arq, "%s", name) != EOF ){
    contp++;
	key = valorString(name);
	key = chaveDiv(key, eleCount);
	insertNode(key, name);
	}
    
    
    while (1) {
        printf("1. Insert\n");
        printf("2. Delet\n");
		printf("3. Count element\n");
        printf("4. Search element\n");
		printf("5. Print\n");
		printf("6. Word counter\n");
		printf("7. Number off diferent words\n");
		printf("8. Exit\n\n");
        printf("Type your choice: ");
        scanf("%d", &op);
        switch (op) {
        case 1:
        	getchar();
            printf("Name:");
            gets(name);
            key = valorString(name);
			key = chaveDiv(key, eleCount);
            insertNode(key, name);
            contp++;
            system("pause");
            system("cls");
            break;
 
        case 2:
            printf("Type a name to delet: ");
            getchar();
            gets(name);
            key = valorString(name);
			key = chaveDiv(key, eleCount);
            deleteNode(key);
            contp--;
            system("pause");
            system("cls");
            break;
            
        case 3:
		    printf("Type the element: ");
            getchar();
            gets(name);
        	key = valorString(name);
			key = chaveDiv(key, eleCount);
            contador = contHash(key);
			printf("The element [%s] appears %d time(s) in the Hash\n", name, contador);              
			system("pause");
			system("cls");
			break;   
 
        case 4:
            printf("Type a name to search: ");
            getchar();
            gets(name);
            key = valorString(name);
			key = chaveDiv(key, eleCount);
            searchNode(key);
            system("pause");
            system("cls");
            break;
        case 5:
        	printf("\n\n");
            imprimeHash();
            printf("\n\n");
            system("pause");
            system("cls");
            break;
       case 6:
            printf("Number of words in the file: %d\n", contp);
            system("pause");
            system("cls");
            break;
        
		case 7:
		contdif = palavraDiferente();
		printf("Number of diferents words in the file: %d\n", contdif);
		system("pause");
		system("cls"); 
		  
		break;
		
        case 8:
        	exit(op);
        default:
            printf("Invalid reqeust\n");
            break;
        }
    }
    return 0;
}

