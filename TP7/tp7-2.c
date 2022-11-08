#include<stdio.h>
#include<stdlib.h>

void input_array(int **tab,int *nb_stud){
    int *loc_tab;
    int loc_nb_stud;
    char buffer;

    printf("How many values : ");
    scanf("%d",&loc_nb_stud);
    scanf("%c",&buffer);

    loc_tab = (int *)calloc(*nb_stud,sizeof(int));
    for (int i=0;i<loc_nb_stud;i++){
        printf("value %d : ",i);
        scanf("%d",loc_tab+i);
        scanf("%c",&buffer);
    }
    *tab = loc_tab;
    *nb_stud = loc_nb_stud;
}

void invert_array(int *tab,int tab_len){
    int aux;
    for (int i=0,j=tab_len-1;i<j;i++,j--){
        aux = tab[i];
        tab[i] = tab[j];
        tab[j] = aux;
    }
}

void print_array(int *tab,int nb_stud){
    for (int i=0;i<nb_stud;i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}

int main(){

    int *my_array;
    int array_len;

    input_array(&my_array,&array_len);

    print_array(my_array,array_len);

    invert_array(my_array,array_len);
    
    print_array(my_array,array_len);

    return EXIT_SUCCESS;
}