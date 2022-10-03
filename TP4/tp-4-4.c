#include<stdio.h>
#include<stdlib.h>

#define N 30

void print_array(int tab[N],int size){
    printf("[");
    for (int i=0;i<size-1;i++){
        printf("%d,",tab[i]);
    }
    printf("%d]\n",tab[size-1]);
}

int main(){

    int tableau[N];

    unsigned char nb_valeur;
    char buffer;

    do {
        printf("nombre de valeurs : ");
        scanf("%hhd",&nb_valeur);
        scanf("%c",&buffer);
    }while (nb_valeur>N);

    printf("rentrez les valeurs\n");


    for (int i = 0;i<nb_valeur;i++){
        printf("entrez valeur %d : ",i);
        scanf("%d",&tableau[i]);
        scanf("%c",&buffer);
        
    }
    printf("valeur initiale\n");
    print_array(tableau,nb_valeur);

    for (int i=0,j=nb_valeur-1;i<j;i++,j--){
        int aux;
        aux = tableau[i];
        tableau[i]=tableau[j];
        tableau[j]=aux;
    }
    printf("valeur finale\n");
    print_array(tableau,nb_valeur);

    return EXIT_SUCCESS;
}