/*
 * tp5-2.c
 *
 *  Created on: 12 oct. 2022
 *      Author: im01231
 */

#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
	printf("a : %d , b : %d \n",*a,*b);
}


int main(){
	int a,b;
	printf("enter two values a b : ");
	scanf("%d %d",&a,&b);

	printf("a : %d , b : %d \n",a,b);

	swap(&a,&b);

	printf("a : %d , b : %d \n",a,b);
	return EXIT_SUCCESS;
}
