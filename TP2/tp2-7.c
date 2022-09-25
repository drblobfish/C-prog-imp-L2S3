#include<stdio.h>
#include<stdlib.h>

int main(){

    float a,b,result;
    int running = 1;
    char choice,buffer;

    while (running)
    {
        printf("a b : ");
        scanf("%f %f",&a,&b);
        scanf("%c",&buffer);

        printf("Addition\tA\nSoustraction\tS\nMultiplication\tM\nDivision\tD\nQuitter\tQ\n");
        scanf("%c",&choice);
        scanf("%c",&buffer);
    
        switch (choice)
        {
        case 'A':
            result = a + b;
            break;
        case 'S':
            result = a-b;
            break;
        case 'M':
            result = a*b;
            break;
        case 'D':
            result = a/b;
            break;
        case 'Q':
            running = 0;
            break;
        default:
            printf("please enter a valid choice\n");
            break;
        }

        if (running){
            printf("result : %f\n",result);
        }
    }
    




    return EXIT_SUCCESS;
}