#include<stdio.h>
#include<stdlib.h>

int main(){

    char a = 10, b = 5;
    printf("La somme de %d et %d est %d\n",a,b,a+b);

    printf("La multiplication de %d et %d est %d\n",a,b,a*b);

    int c = 20,d = 6;
    printf("La division de %d par %d est %6.3f\n",c,d,(float)c / d);

    printf("%d+%d=%d \t %d*%d=%d \t %6.2f/%6.2f=%6.3f\n",
        a,b,a+b,
        a,b,a*b,
        (float)c,(float)d,((float)c)/d
    );

    return EXIT_SUCCESS;
}