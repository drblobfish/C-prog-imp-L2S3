/*
 * tp5-3.c
 *
 *  Created on: 12 oct. 2022
 *      Author: im01231
 */

#include<stdio.h>
#include<stdlib.h>

void min_max(int a,int b, int c, int *min, int *max){
	*min = a;
	*max = a;

	if (b>*max) *max = b;
	if (b<*min) *min = b;

	if (c>*max) *max = c;
	if (c<*min) *min = c;
}

int main(){
	int a,b,c, min , max;
	printf("enter 3 number a b c : ");
	scanf("%d %d %d",&a,&b,&c);

	min_max( a, b,  c, &min, &max);

	printf("min : %d \tmax : %d",min,max);

	return EXIT_SUCCESS;
}
