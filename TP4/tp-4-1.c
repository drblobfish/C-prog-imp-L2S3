#include<stdio.h>
#include<stdlib.h>

int main(){

    int tableau[20];
    unsigned char nb_valeur;
    char buffer;

    do {
        printf("nombre de valeurs : ");
        scanf("%hhd",&nb_valeur);
        scanf("%c",&buffer);
    }while (nb_valeur>20);    


    for (int i = 0;i<nb_valeur;i++){
        printf("entrez valeur %d : ",i);
        scanf("%d",&tableau[i]);
        scanf("%c",&buffer);
        
    }

    printf("[");
    for (int i=0;i<nb_valeur-1;i++){
        printf("%d,",tableau[i]);
    }
    printf("%d]\n",tableau[nb_valeur-1]);



    return EXIT_SUCCESS;
}