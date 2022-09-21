#include<stdio.h>
#include<stdlib.h>

int main(){
    int jour;
    int mois;
    int annee;

    int nb_correct;

    printf("Introduisez la date (jour mois annee) : ");
    nb_correct = scanf("%d %d %d",&jour,&mois,&annee);

    printf("\nDonnees correctement lues : %d\n",nb_correct);

    printf("/****Affichage de la date de saisie****/\n");
    printf("Jour : %d\n",jour);
    printf("Mois : %d\n",mois);
    printf("annee : %d\n",annee);

    return EXIT_SUCCESS;
}