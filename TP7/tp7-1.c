#include<stdio.h>
#include<stdlib.h>

void input_grades(int **tab,int *nb_stud){
    int *loc_tab;
    int loc_nb_stud;
    char buffer;

    printf("How many students : ");
    scanf("%d",&loc_nb_stud);
    scanf("%c",&buffer);

    loc_tab = (int *)calloc(*nb_stud,sizeof(int));
    for (int i=0;i<loc_nb_stud;i++){
        printf("grade student %d : ",i);
        scanf("%d",loc_tab+i);
        scanf("%c",&buffer);
    }
    *tab = loc_tab;
    *nb_stud = loc_nb_stud;
};

void compute_stats(int *tab,int nb_stud,float *mean, int *min, int*max){
    int sum=0;
    int loc_min = *tab;
    int loc_max = *tab;
    for (int i=0;i<nb_stud;i++){
        sum += tab[i];
        if (tab[i]<loc_min) loc_min = tab[i];
        if (tab[i]>loc_max) loc_max = tab[i];
    }
    *mean = sum/(float)nb_stud;
    *min = loc_min;
    *max = loc_max;
}

void print_array(int *tab,int nb_stud){
    for (int i=0;i<nb_stud;i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}




int main(){
    int *tab;
    int nb_stud;

    input_grades(&tab,&nb_stud);

    float mean;
    int min,max;
    compute_stats(tab,nb_stud,&mean,&min,&max);

    print_array(tab,nb_stud);

    printf("mean : %f\tmin : %d\tmax %d\n",mean,min,max);

    return EXIT_SUCCESS;
}