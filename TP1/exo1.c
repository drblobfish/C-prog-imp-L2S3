/* programme de calcul de circonference*/

#include<stdio.h>

#include <stdlib.h>

float circonference(float rayon){
    float pi = 3.1415;
    float circon;
    circon = 2 * pi * rayon;
    return circon ;
}

int main(){
    float r;
    int i, n=5;

    /* saisie par l'utilisateur de n rayons de calcul
    des n circonferences correspondantes*/

    for (i = 0; i < n; i++)
    {
        printf("Saisie du rayon %d\n",i);
        scanf("%f",&r);
        printf("La circonference est de : %.2f\n",circonference(r));
    }

    return EXIT_SUCCESS;
    
}