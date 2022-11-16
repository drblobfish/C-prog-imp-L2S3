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

typedef struct CONCURRENT
{
    int dossard;
    TEMPS temps;
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

void saisirPerf(COMPETITION *competition){
    char buffer;

    for (int i=0;i<competition->nb_concurrent;i++){
        printf("Dossard n° %d. temps (mm ss dd) : ",competition->array_concurrent[i].dossard);
        scanf("%d %d %d",
            &(competition->array_concurrent[i].temps.minute),
            &(competition->array_concurrent[i].temps.seconde),
            &(competition->array_concurrent[i].temps.dixieme)
        );
        scanf("%c",&buffer);
    }
}

void saisie_score(CONCURRENT *concurrent){
    printf("Temps (mm ss dd) : ");
    scanf("%d %d %d",
        &(concurrent->temps.minute),
        &(concurrent->temps.seconde),
        &(concurrent->temps.dixieme)
    );
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
    
}

void affiche_competition(COMPETITION *competition){
    printf("====== COMPETITION ======\n");
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