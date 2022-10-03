#include<stdio.h>
#include<stdlib.h>

#define N 50

void print_array(int tab[N],int size){
    printf("[");
    for (int i=0;i<size-1;i++){
        printf("%d,",tab[i]);
    }
    printf("%d]\n",tab[size-1]);
}

int main(){

    int tableau[N];
    int t1[N];
    int effectif[N];

    int nb_diff_value=0;

    unsigned char nb_valeur;
    char buffer;

    do {
        printf("nombre de valeurs : ");
        scanf("%hhd",&nb_valeur);
        scanf("%c",&buffer);
    }while (nb_valeur>N);

    printf("rentrez les valeurs dans l'ordre croissant\n");


    for (int i = 0;i<nb_valeur;i++){
        printf("entrez valeur %d : ",i);
        scanf("%d",&tableau[i]);
        scanf("%c",&buffer);
        
    }

    printf("Original array\n");
    print_array(tableau,nb_valeur);

    t1[0] = tableau[1];
    effectif[0]=1;

    for (int i = 1;i<nb_valeur;i++){
        if (tableau[i] == tableau[i-1]){
            effectif[nb_diff_value] ++;
        }
        else{
            nb_diff_value++;
            t1[nb_diff_value] = tableau[i];
            effectif[nb_diff_value]=1;
        }
        
    }
    nb_diff_value++;

    printf("valeurs\n");
    print_array(t1,nb_diff_value);
    printf("effectif\n");
    print_array(effectif,nb_diff_value);

    return EXIT_SUCCESS;
}