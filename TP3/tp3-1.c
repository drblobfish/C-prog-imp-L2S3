#include<stdio.h>
#include<stdlib.h>

int main(){

    int x = 15;

    printf("adresse x : %p\tvaleur x : %d\n",&x,x);

    int *pInt = &x;

    printf("adresse pInt : %p\tcontenu pInt %p\tvaleur pointee %d\n",&pInt,pInt,*pInt);

    int *ptrInt = (int *) malloc(sizeof(int));
    *ptrInt = 100;

    printf("adresse ptrInt %p\t contenu ptrInt %p\tvaleur pointee %d\n",&ptrInt,ptrInt,*ptrInt);

    *pInt = 200;

    printf("adresse x : %p\tvaleur x : %d\n",&x,x);

    printf("adresse pInt : %p\tcontenu pInt %p\tvaleur pointee %d\n",&pInt,pInt,*pInt);

    printf("adresse ptrInt %p\t contenu ptrInt %p\tvaleur pointee %d\n",&ptrInt,ptrInt,*ptrInt);


    free(ptrInt);

    return EXIT_SUCCESS;
}