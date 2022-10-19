#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STR_MAX 30


void invert_maj_min(char *input_str, char *output_str){
    int str_not_finished = 1;
    for (int i=0;str_not_finished && i<STR_MAX;i++){
        char letter = input_str[i];
        if (letter == '\0'){
            str_not_finished = 0;
        }
        if (letter >= 'A' && letter <='Z'){
            letter = letter + 'a'-'A';
        }
        else if (letter >= 'a' && letter <= 'z'){
            letter = letter - 'a'+'A';
        }
        output_str[i] = letter;
    }
}


int main(){

    char ch_input[STR_MAX],ch_output[STR_MAX];
    printf("entrez une chaine : ");
    fgets(ch_input,STR_MAX,stdin);

    invert_maj_min(ch_input,ch_output);

    printf("%s",ch_output);

    return EXIT_SUCCESS;
}