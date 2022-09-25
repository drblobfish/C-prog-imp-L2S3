#include<stdio.h>
#include<stdlib.h>

#define PI 3.14

int main(){
    float c;
    printf("c : ");
    scanf("%f",&c);

    float area = (c*c)*(1 - PI/4); 

    printf("area : %f\n",area);
}