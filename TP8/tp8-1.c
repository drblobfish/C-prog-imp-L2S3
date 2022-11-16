#include <stdio.h>
#include <stdlib.h>

typedef struct DATE
{
    int jour;
    int mois;
    int annee;
}DATE;

typedef struct EMPLOYE
{
    char nom[20];
    DATE date_embauche;
    DATE date_poste;
}EMPLOYE;

typedef struct ENTREPRISE
{
    int nb_employe;
    EMPLOYE * array_employe;
}ENTREPRISE;

void saisie(EMPLOYE* employe){
    char buffer;
    char poste_egal_embauche;

    printf("Nom : ");
    scanf("%s",employe->nom);
    printf("Date embauche (jj mm aa) : ");
    scanf("%d %d %d",
        &(employe->date_embauche.jour),
        &(employe->date_embauche.mois),
        &(employe->date_embauche.annee));
    scanf("%c",&buffer);
    do {
        printf("Date poste = date embauche ? (Y/N) : ");
        scanf("%c",&poste_egal_embauche);
        scanf("%c",&buffer);
    }while(poste_egal_embauche!='Y' && poste_egal_embauche!='N');
    if (poste_egal_embauche == 'Y'){
        employe->date_poste = employe->date_embauche;
    }
    else{
        printf("Date poste (jj mm aa) : ");
        scanf("%d %d %d",
            &(employe->date_poste.jour),
            &(employe->date_poste.mois),
            &(employe->date_poste.annee));
        scanf("%c",&buffer);
    }
    
}

void affiche(EMPLOYE *employe){
    printf("Nom : %s\n",employe->nom);
    printf("Date embauche : %d %d %d\n",
        employe->date_embauche.jour,
        employe->date_embauche.mois,
        employe->date_embauche.annee);
    printf("Date poste : %d %d %d\n",
        employe->date_poste.jour,
        employe->date_poste.mois,
        employe->date_poste.annee);
}

void saisie_plusieurs_employés(ENTREPRISE *entreprise){
    printf("Nombre d'employe : ");
    scanf("%d",&(entreprise->nb_employe));

    entreprise->array_employe = (EMPLOYE *)calloc(entreprise->nb_employe,sizeof(EMPLOYE));
    if (entreprise->array_employe == NULL){
        printf("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    for (int i=0;i<entreprise->nb_employe;i++){
        saisie(entreprise->array_employe+i);
    }
}

void affiche_plusieurs_employés(ENTREPRISE * entreprise){
    for (int i=0;i<entreprise->nb_employe;i++){
        affiche(entreprise->array_employe+i);
    }
}

int main(){

    ENTREPRISE entreprise;

    saisie_plusieurs_employés(&entreprise);

    affiche_plusieurs_employés(&entreprise);

    free(entreprise.array_employe);

    return EXIT_SUCCESS;
}