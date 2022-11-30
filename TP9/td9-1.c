#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STR_MAX_LEN 30
#define MAX_EMPLOYE 100

typedef enum GENRE{
    MASCULIN,
    FEMININ
}GENRE;

typedef char NOM[STR_MAX_LEN];

typedef struct ADRESSE{
    unsigned int num;
    NOM rue;
    unsigned int code;
    NOM ville;
}ADRESSE;

typedef enum SITUATION_MILITAIRE{
    LIBERE,
    EXEMPTE,
    REFORME,
    INCORPORABLE
}SITUATION_MILITAIRE;

typedef union COMPLEMENT{
    SITUATION_MILITAIRE situation_militaire;
    NOM nom_jeune_fille;
}COMPLEMENT;

typedef struct PERSONNE{
    NOM nom;
    NOM prenom;
    GENRE genre;
    ADRESSE adresse;
    COMPLEMENT complement;
}PERSONNE;

typedef struct SOCIETE
{
    unsigned int nb_employe;
    PERSONNE tableau_employe[MAX_EMPLOYE];
}SOCIETE;

void fgets_strip(char *output){
    fgets(output,STR_MAX_LEN-1,stdin);
    output[strlen(output)-1] = '\0';
}

void saisie_adresse(ADRESSE *adresse){
    char buffer;
    printf("n° : ");
    scanf("%d",&(adresse->num));
    scanf("%c",&buffer);

    printf("Rue : ");
    fgets_strip(adresse->rue);

    printf("Code postal : ");
    scanf("%d",&(adresse->code));
    scanf("%c",&buffer);
    
    printf("Ville : ");
    fgets_strip(adresse->ville);
}

void saisie_personne(PERSONNE *personne){
    char buffer;
    printf("Nom : ");
    fgets_strip(personne->nom);
    printf("Prenom : ");
    fgets_strip(personne->prenom);
    
    saisie_adresse(&(personne->adresse));

    char genre;
    printf("Genre (M/F) : ");
    scanf("%c%c",&genre,&buffer);
    
    switch (genre)
    {
    case 'M':
        personne->genre = MASCULIN;
        char situ_Mili;
        printf("Situation Militaire (L/E/R/I) : ");
        scanf("%c%c",&situ_Mili,&buffer);
        switch (situ_Mili)
        {
        case 'L':
            personne->complement.situation_militaire = LIBERE;
            break;
        case 'E':
            personne->complement.situation_militaire = EXEMPTE;
            break;
        case 'R':
            personne->complement.situation_militaire = REFORME;
            break;
        case 'I':
            personne->complement.situation_militaire = INCORPORABLE;
            break;
        default:
            break;
        }
        break;
    case 'F':
        personne->genre = FEMININ;
        printf("Nom de jeune fille : ");
        fgets_strip(personne->complement.nom_jeune_fille);
        break;
    default:
        printf("Genre inconnu");
        break;
    }
}

void saisie_fiche(SOCIETE *societe){
    char buffer;
    printf("Nombre d'employe : ");
    scanf("%d",&(societe->nb_employe));
    scanf("%c",&buffer);

    for (int i=0;i<societe->nb_employe;i++){
        saisie_personne(societe->tableau_employe+i);
    }
}

void affiche_personne(PERSONNE *personne){
    printf("Nom : %s\n",personne->nom);
    printf("Prenom : %s\n",personne->prenom);
    printf("Adresse : %d %s %d %s\n",personne->adresse.num,personne->adresse.rue,personne->adresse.code,personne->adresse.ville);
    printf("Genre : ");
    switch (personne->genre)
    {
    case FEMININ:
        printf("Feminin\n");
        break;
    case MASCULIN:
        printf("Masculin\n");
        break;
    default:
        break;
    }
    if (personne->genre == MASCULIN){
        printf("Situation militaire : ");
        switch (personne->complement.situation_militaire)
        {
        case LIBERE:
            printf("libere\n");
            break;
        case EXEMPTE:
            printf("exempte\n");
            break;
        case REFORME:
            printf("reforme\n");
            break;
        case INCORPORABLE:
            printf("incorporable\n");
            break;
        default:
            break;
        }
    }
    else {
        printf("Nom de jeune fille : %s\n",personne->complement.nom_jeune_fille);
    }
}

void affiche(SOCIETE *societe){
    printf("=== SOCIETE ===\n\n");
    for (int i=0;i<societe->nb_employe;i++){
        
        affiche_personne(societe->tableau_employe+i);
        printf("---***---\n");
    }
}


int main(){

    SOCIETE societe;

    saisie_fiche(&societe);

    affiche(&societe);

    return EXIT_SUCCESS;
}