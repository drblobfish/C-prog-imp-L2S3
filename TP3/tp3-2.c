#include<stdio.h>
#include<stdlib.h>

int main(){

    int nb_value;
    char buffer;

    printf("Nombre de valeur à saisir : ");
    scanf("%d",&nb_value);
    scanf("%c",&buffer);

    float *ptrList = (float *) calloc(nb_value,sizeof(float));

    for (int i = 0; i < nb_value;i++){
        printf("valeur n° %d : ",i);
        scanf("%f",ptrList+i);
        scanf("%c",&buffer);
    }


    float *ptrMin = ptrList;
    float *ptrMax = ptrList;

    for (int i = 0; i < nb_value;i++){
        if (*(ptrList+i) > *ptrMax){
            ptrMax = ptrList+i;
        }
        else if (*(ptrList+i) < *ptrMin){
            ptrMin = (ptrList+i);
        }

        printf("adresse valeur n° %d : %p\tvaleur n° %d : %f\n",i,ptrList+i,i,*(ptrList+i));
    }

    printf("contenu ptrMax : %p\t valeur pointée : %f\n",ptrMax,*ptrMax);
    printf("contenu ptrMin : %p\t valeur pointée : %f\n",ptrMin,*ptrMin);

    return EXIT_SUCCESS;
}