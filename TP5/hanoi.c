#include<stdio.h>
#include<stdlib.h>


void hanoi(int nb_disk,int from,int helper,int to){
    if (nb_disk==1){
        printf("move disk %d from %d to %d\n",nb_disk,from,to);
        return ;
    }
    hanoi(nb_disk-1,from,to,helper);
    printf("move disk %d from %d to %d\n",nb_disk,from,to);
    hanoi(nb_disk-1,helper,from,to);
}

int main(){
    int n;
    printf("enter n : ");
    scanf("%d",&n);
    hanoi(n,1,2,3);

    return EXIT_SUCCESS;
}