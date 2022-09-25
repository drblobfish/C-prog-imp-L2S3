#include<stdio.h>
#include<stdlib.h>

int main(){
    int sum,coin5,coin2,coin1;
    printf("Enter amount : ");
    scanf("%d",&sum);

    coin5 = sum/5;

    coin2 = (sum%5)/2;

    coin1 = (sum%5)%2;

    printf("5 : %d \n2 : %d \n1 : %d \n",coin5,coin2,coin1);

}