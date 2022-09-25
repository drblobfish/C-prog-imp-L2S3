#include<stdio.h>
#include<stdlib.h>

int main(){

    float a,b,c;

    printf("enter lengths (a b c) : ");
    scanf("%f %f %f",&a,&b,&c);

    if (a==b || b==c || c==a){
        if (a==b==c){
            printf("equilateral\n");
        }
        else{
            printf("isocele\n");
        }
    }
    else if (a*a == b*b + c*c){
        printf("rectangle en a\n");
    }
    else if (b*b == a*a + c*c){
        printf("rectangle en b\n");
    }
    else if(c*c == a*a + b*b){
        printf("rectangle en c\n");
    }
    else {
        printf("unspecified\n");
    }

    return EXIT_SUCCESS;
}