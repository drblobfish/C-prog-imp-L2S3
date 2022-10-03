#include<stdio.h>
#include<stdlib.h>

int main(){

    int tableau[10][10];
    unsigned char nb_x,nb_y;
    char buffer;

    do {
        printf("nombre de ligne et de colone (x y) : ");
        scanf("%hhd %hhd",&nb_x,&nb_y);
        scanf("%c",&buffer);
    }while (nb_x>10 || nb_y>10);


    for (int i = 0;i<nb_x;i++){
        for (int j = 0; j<nb_y;j++){
            printf("entrez valeur %d,%d : ",i,j);
            scanf("%d",&tableau[i][j]);
            scanf("%c",&buffer);
        }
    }

    for (int i = 0;i<nb_x;i++){
        for (int j = 0; j<nb_y;j++){
            printf("%d ",tableau[i][j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}