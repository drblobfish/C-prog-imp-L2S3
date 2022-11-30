#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20

typedef struct TEMPS
{
    int minute;
    int seconde;
    int dixieme;
}TEMPS;

typedef enum CIBLE
{
    ATTEINTE,
    NON_ATTEINTE
}CIBLE;

typedef struct CONCURRENT
{
    int dossard;
    TEMPS temps;
    CIBLE cible[4][5];
    char *nom;
    char *prenom;
    char *natio;
}CONCURRENT;

typedef struct COMPETITION
{
    int nb_concurrent;
    CONCURRENT *array_concurrent;
}COMPETITION;

char *saisie_chaine(){
    char buffer[NAME_LEN];
    char *s;
    fgets(buffer,NAME_LEN-1,stdin);
    int length = strlen(buffer);
    s = (char *)calloc(length,sizeof(char));
    if (s == NULL){
        printf("Memory allocation problem");
        exit(EXIT_FAILURE);
    }
    strncpy(s,buffer,length-1);
    return s;
}

void saisie_concurrent(CONCURRENT *concurrent){
    TEMPS default_time = {0,0,0};
    printf("Nom : ");
    concurrent->nom = saisie_chaine();
    printf("Prenom : ");
    concurrent->prenom = saisie_chaine();
    printf("Nationalite : ");
    concurrent->natio = saisie_chaine();
    concurrent->temps = default_time;

    for (int i=0;i<4;i++){
        for (int j=0;j<5;j++){
            concurrent->cible[i][j] = NON_ATTEINTE;
        }
    }
}

void inscrire(COMPETITION *competition){
    char buffer;
    printf("Nombre de participants : ");
    scanf("%d",&(competition->nb_concurrent));
    scanf("%c",&buffer);
    
    competition->array_concurrent = (CONCURRENT *) calloc(competition->nb_concurrent,sizeof(CONCURRENT));
    if (competition->array_concurrent == NULL){
        printf("Memory allocation problem\n");
    }

    for (int i=0;i<competition->nb_concurrent;i++){
        saisie_concurrent(competition->array_concurrent+i);
        competition->array_concurrent[i].dossard = i;
    }
}

void saisie_score(CONCURRENT *concurrent){
    char buffer;
    char cible;
    printf("Dossard n° %d. temps (mm ss dd) : ",concurrent->dossard);
    scanf("%d %d %d",
        &(concurrent->temps.minute),
        &(concurrent->temps.seconde),
        &(concurrent->temps.dixieme)
    );
    scanf("%c",&buffer);

    for (int i=0;i<4;i++){
        for (int j=0;j<5;j++){
            printf("Cible %d %d A/N: ",i,j);
            scanf("%c%c",&cible,&buffer);
            if (cible == 'A'){
                concurrent->cible[i][j] = ATTEINTE;
            }
            else if (cible == 'N'){
                concurrent->cible[i][j] = NON_ATTEINTE;
                if (concurrent->temps.minute != -1){
                    concurrent->temps.minute += 1;
                }
            }
            else {
                printf("Invalide\n");
            }
        }
    }
}

void saisirPerf(COMPETITION *competition){
    char buffer;
    char cible;

    for (int i=0;i<competition->nb_concurrent;i++){
        saisie_score(competition->array_concurrent+i);
    }
}

void affiche_concurrent(CONCURRENT *concurrent){
    printf("Nom : %s\n",concurrent->nom);
    printf("Prenom : %s\n",concurrent->prenom);
    if (concurrent->temps.minute == -1){
        printf("Abandon\n");
    }
    else {
        printf("Temps : %d %d %d\n",
            concurrent->temps.minute,
            concurrent->temps.seconde,
            concurrent->temps.dixieme);
    }
    printf("Cible : ");
    for (int i=0;i<4;i++){
        printf("\n");
        for (int j=0;j<5;j++){
            if (concurrent->cible[i][j]==ATTEINTE){
                printf("X");
            }
            else {
                printf("O");
            }
            printf(" ");
        }
    }
    printf("\n");
}

void affiche_competition(COMPETITION *competition){
    printf("\n====== COMPETITION ======\n");
    printf("Nombre de participant : %d\n\n",competition->nb_concurrent);
    for (int i=0;i<competition->nb_concurrent;i++){
        affiche_concurrent(competition->array_concurrent+i);
        printf("-----------------\n");
    }
}


int main(){

    COMPETITION competition;

    inscrire(&competition);

    saisirPerf(&competition);

    affiche_competition(&competition);

    free(competition.array_concurrent);

    return EXIT_SUCCESS;
}