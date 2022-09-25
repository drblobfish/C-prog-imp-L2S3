#include<stdio.h>
#include<stdlib.h>

#define VERSION 1

void version0(){
    int a,b,c,d;
    printf("4 integers separtated by spaces : ");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("\n");

    int result = a+b+c+d;

    printf("result : %d\n",result);
}

void version1(){
    int number;
    int sum = 0;

    for (char i = 0; i < 4; i++)
    {
        printf("enter number %d : ",i);
        scanf("%d",&number);
        printf("\n");
        sum += number;
    }
    printf("result : %d\n",sum);
}

int main(){
    if (VERSION) {
        version0();
    }
    else {
        version1();
    }
}