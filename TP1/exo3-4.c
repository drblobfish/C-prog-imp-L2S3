#include<stdio.h>
#include<stdlib.h>

int main(){
    int a,b;
    
    printf("entrez a,b\n");
    scanf("%d,%d",&a,&b);

    int s = a+b;
    int p = a*b;
    int c1 = a*a;
    int c2 = b*b;

    printf("S=%d \nP=%d \nC1=%d \nC2=%d \n",
    s,p,c1,c2);
}