#include<stdio.h>
#include<stdlib.h>


int main(){
    char *jours[]={
        "Pas un jour",
        "Lundi",
        "Mardi",
        "Mercredi",
        "Jeudi",
        "Vendredi",
        "Samedi",
        "Dimanche"
        };
    
    int nb;
    
    printf("Entrez le numero d'un jour : ");
    scanf("%d",&nb);

    if (nb<0 || nb>7){
        nb = 0;
    }

    printf("%s\n",jours[nb]);

    return EXIT_SUCCESS;
}