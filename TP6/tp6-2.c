#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STR_MAX 30

const char chiffreRomain[]="IVXLCDM";
const int chiffreArabe[]={1,5,10,50,100,500,1000};

int Romain_to_arab(char * romain){

    int max_roman = 0;
    int j,i;

    int arab = 0;

    for (i = strlen(romain)-2;i>=0;i--){
        j=0;
        for (;chiffreRomain[j]!=romain[i] && j<=6;j++){}

        if (j==7){
            printf("Invalid character in roman numeral\n");
            exit(0);
        }
        
        if (j>=max_roman){
            //printf("%c %c %d  %d : positive\n",romain[i], chiffreRomain[j],j,max_roman);
            arab += chiffreArabe[j];
            max_roman = j;
        }
        else {
            //printf("%c %c %d %d : negative\n",romain[i], chiffreRomain[j],j,max_roman);
            arab -= chiffreArabe[j];
        }
    }

    return arab;
}


int main(){

    char ch_input[STR_MAX];
    printf("enter a roman numeral : ");
    fgets(ch_input,STR_MAX,stdin);

    int nb = Romain_to_arab(ch_input);

    printf("%d\n",nb);

    return EXIT_SUCCESS;
}