#include<stdio.h>
#include<stdlib.h>


int main(){
    int nb;
    int sum = 0;
    int prod=1;
    int count=0;
    char buffer;

    do
    {
        printf("enter a number : ");
        scanf("%d",&nb);
        scanf("%c",&buffer);
        sum += nb;
        prod *= nb;
        count++;
    } while (nb<1 || 15<nb);

    printf("sum : %d \tproduct : %d \tmean : %f\n",sum,prod,sum/(float)count);
    
}