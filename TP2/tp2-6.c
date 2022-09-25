#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

    float a,b,c;

    printf("a b c : ");
    scanf("%f %f %f",&a,&b,&c);

    float delta = (b*b) - (4*a*c);

    if (delta > 0){
        float x1,x2;
        x1 = (-b -sqrt(delta))/(2*a);
        x2 = (-b +sqrt(delta))/(2*a);
        printf("x1 = %f ; x2 = %f\n",x1,x2);
    }
    else if (delta <0){
        float x1re,x1im,x2re,x2im;
        x1re = -b/(2*a);
        x1im = -sqrt(-delta)/(2*a);
        x2re = x1re;
        x2im = -x1im;

        printf("x1 = %f+i%f ; x2 %f+i%f\n",x1re,x1im,x2re,x2im);
    }
    else {
        float x = -b/(2*a);
        printf("x = %f",x);
    }


    return EXIT_SUCCESS;
}