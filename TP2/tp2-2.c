#include<stdio.h>
#include<stdlib.h>

int main(){
    int a,b;

    printf("enter two integers separated with space : ");
    scanf("%d %d",&a,&b);

    printf("division : %f \ninteger division %d \nmodulo %d \n",(float)a/b,a/b,a%b);
}