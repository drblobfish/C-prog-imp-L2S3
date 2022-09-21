#include<stdio.h>
#include<stdlib.h>

int main(){

    long int __3;

    __3 = 34;

    unsigned char c = 0;

    printf("%ld\n",__3);

    for (int i = 0; i < 255; i++)
    {
        c++;
        printf("%u : %c\n",c,c);
    }

    return EXIT_SUCCESS;
}