#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 20

void enter_verb(char *verb,int *verb_len){
    do {
        printf("enter a valid verb : ");
        fgets(verb,MAX_LEN-1,stdin);
        *verb_len = strlen(verb);
    }while(verb[*verb_len - 2] != 'r' || verb[*verb_len - 3] != 'e');
    
}

void conjugation(char*verb,int verb_len){
    char radical[MAX_LEN];
    strcpy(radical,verb);
    radical[verb_len-3] = '\0';

    printf("Je %se\n",radical);
    printf("Tu %ses\n",radical);
    printf("Il/Elle %se\n",radical);
    printf("Nous %sons\n",radical);
    printf("Vous %sez\n",radical);
    printf("Ils %sent\n",radical);
}


int main(){

    char verb[MAX_LEN];
    int verb_len;

    enter_verb(verb,&verb_len);

    printf("Conjugons le verbe %s\n\n",verb);

    conjugation(verb,verb_len);



    return EXIT_SUCCESS;
}