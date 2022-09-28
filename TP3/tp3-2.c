#include<stdio.h>
#include<stdlib.h>

int main(){

    int nb_value;
    char buffer;

    printf("Nombre de valeur a saisir : ");
    scanf("%d",&nb_value);
    scanf("%c",&buffer);

    float *ptrList = NULL;
    ptrList =  (float *) calloc(nb_value,sizeof(float));

    if (ptrList == NULL){
        printf("Heap allocation error");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < nb_value;i++){
        printf("valeur n0 %d : ",i);
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

        printf("adresse valeur n0 %d : %p\tvaleur n0 %d : %f\n",i,ptrList+i,i,*(ptrList+i));
    }

    printf("contenu ptrMax : %p\t valeur pointee : %f\n",ptrMax,*ptrMax);
    printf("contenu ptrMin : %p\t valeur pointee : %f\n",ptrMin,*ptrMin);

    free(ptrList);

    return EXIT_SUCCESS;
}