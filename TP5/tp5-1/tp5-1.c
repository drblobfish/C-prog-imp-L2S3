/*
 * tp5-1.c
 *
 *  Created on: 12 oct. 2022
 *      Author: im01231
 */

#include<stdio.h>
#include<stdlib.h>

int mult_2(int nb){
	return (nb%2)==0;
}

int mult_3(int nb){
	return (nb%3)==0;
}

int main(){
	int number;
	printf("Enter a number : ");
	scanf("%d",&number);

	int div2 = mult_2(number);
	int div3 = mult_3(number);

	if (div2) printf("multiple de 2\n");
	if (div3) printf("multiple de 3\n");
	if (div3 && div2) printf("multiple de 6\n");

	return EXIT_SUCCESS;
}
