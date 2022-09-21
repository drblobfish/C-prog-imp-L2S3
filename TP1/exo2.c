#include<stdio.h>
#include<stdlib.h>
// Les includes doivent etre au debut du fichier

// il ne peut y avoir deux fonctions main
// cette fonction ne retourne pas de float
void dire_bonjour(){
    printf("Bonjour\n");
}

int main(){
    /*nombre n'est jamais utilise et dois donc
    etre supprime*/
    //int nombre=4;
    // chaque instruction se termine par ;
    printf("au revoir \n");
    // realise l'affichage d'au revoir a l'ecran
    // les commentaires doivent etre indiques avec // ou /* */
    // c'est plus lisible d'utiliser la valeur EXIT_SUCCESS de stdlib
    return EXIT_SUCCESS;
}
