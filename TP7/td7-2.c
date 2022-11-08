#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char *ptab;
    char tab[32];
    char ch1[] = "Bonjour";
    char ch2[15];

    strcpy(tab,"QW");
    strcpy(ch2,ch1);
    ptab = (char *) calloc(10,sizeof(char));
    if (ptab==NULL){
        perror("memory problem");
    }
    strcpy(ptab,"ASDFGHJKL");

    printf("tab : %s\tptab : %s\n",tab,ptab);
    printf("tab : %c\tptab : %c\n",*tab,*ptab);
    printf("tab : %c\tptab : %c\n",tab[1],ptab[1]);
    printf("tab : %c\tptab : %c\n",*(tab+1),*(ptab+1));
    printf("tab : %c\tptab : %c\n",*tab+1,*ptab+1);

    return EXIT_SUCCESS;

}