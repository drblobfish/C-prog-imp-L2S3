#include<stdio.h>
#include<stdlib.h>

void convertToBinary(int a)
{
    /* step 1 */
    if (a > 1)
        convertToBinary(a / 2);

    /* step 2 */
    printf("%d", a % 2);
}

int main(){
    int x,p,n;

    printf("x p n : ");
    scanf("%d %d %d",&x,&p,&n);

    int mask = 0;

    for (int i = p; i < p+n; i++)
    {
        mask += 1<<i;
    }

    int switched = x ^ mask;

    printf("orig : ");
    convertToBinary(x);
    printf("\n");

    printf("mask : ");
    convertToBinary(mask);
    printf("\n");

    printf("switched : ");
    convertToBinary(switched);
    printf("\n");

    printf("switched : %d\n",switched);


    return EXIT_SUCCESS;
}