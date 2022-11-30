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

void read_grades(char *file_name,int **tab,int *nb_stud){
    FILE *grade_file = fopen(file_name,"r");
    if (grade_file == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    char buffer;
    int *loc_tab;
    
    fscanf(grade_file,"%d",nb_stud);
    fscanf(grade_file,"%c",&buffer);

    loc_tab = (int *)calloc(*nb_stud,sizeof(int));

    for (int i=0;i<*nb_stud;i++){
        fscanf(grade_file,"%d",loc_tab+i);
        fscanf(grade_file,"%c",&buffer);
    }
    *tab = loc_tab;

    fclose(grade_file);
}

void write_grades(char *file_name,int *tab,int nb_stud){
    FILE *grade_file = fopen(file_name,"w");

    fprintf(grade_file,"%d\n",nb_stud);
    for (int i=0;i<nb_stud;i++){
        fprintf(grade_file,"%d;",tab[i]);
    }
    fclose(grade_file);
}

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


void help(){
    printf(
        "Usage tp2-1 [mode] [file name]\n"
        "mode :\n"
        " - w : enter grades with a keyboard and save it to file\n"
        " - r : read grades from file and compute statistics\n"
        " - h : print help message\n");
}

int main(int argc, char *argv[]){
    
    int *tab;
    int nb_stud;

    if (argc!=3 ||*argv[1]=='h'){
        help();
        exit(EXIT_FAILURE);
    }

    switch (*argv[1])
    {
    case 'w':
        input_grades(&tab,&nb_stud);
        write_grades(argv[2],tab,nb_stud);
        break;
    case 'r':
        read_grades(argv[2],&tab,&nb_stud);
        break;
    default:
        break;
    }

    float mean;
    int min,max;
    compute_stats(tab,nb_stud,&mean,&min,&max);

    print_array(tab,nb_stud);

    printf("mean : %f\tmin : %d\tmax %d\n",mean,min,max);

    free(tab);

    return EXIT_SUCCESS;
}