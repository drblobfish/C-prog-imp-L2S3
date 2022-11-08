#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NVAL 10

int main(){
    int i,min,max;
    int t[NVAL];

    printf("donnez %d valeurs\n",NVAL);

    for (i=0;i<NVAL;i++)
        scanf("%d",t+i);

    max = min = *t;
    for(i=1;i<NVAL;i++){
        max = (*(t+i) > max) ? *(t+i) : max;
        min = (*(t+i) < min) ? *(t+i) : min;
    }

    printf("max : %d\t min : %d\n",max,min);


    return EXIT_SUCCESS;
}