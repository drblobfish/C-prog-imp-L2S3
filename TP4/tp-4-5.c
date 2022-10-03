#include<stdio.h>
#include<stdlib.h>

#define N 10

int main(){

    int tableau[N][N];
    unsigned char nb_x,nb_y;
    char buffer;

    do {
        printf("nombre de ligne et de colone (x y) : ");
        scanf("%hhd %hhd",&nb_x,&nb_y);
        scanf("%c",&buffer);
    }while (nb_x>N || nb_y>N);


    for (int i = 0;i<nb_x;i++){
        for (int j = 0; j<nb_y;j++){
            printf("entrez valeur %d,%d : ",i,j);
            scanf("%d",&tableau[i][j]);
            scanf("%c",&buffer);
        }
    }

    printf("matrice\n");

    for (int i = 0;i<nb_x;i++){
        for (int j = 0; j<nb_y;j++){
            printf("%d ",tableau[i][j]);
        }
        printf("\n");
    }

    printf("matrice.T\n");

    for (int j = 0; j<nb_y;j++){
        for (int i = 0;i<nb_x;i++){
            printf("%d ",tableau[i][j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}