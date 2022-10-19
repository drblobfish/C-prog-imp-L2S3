/*
 * tp5-4.c
 *
 *  Created on: 12 oct. 2022
 *      Author: im01231
 */

#include<stdio.h>
#include<stdlib.h>

int coef_binom(int p, int n){
	if (p==0 || p==n){
		return 1;
	}
	return coef_binom(p-1,n-1) + coef_binom(p,n-1);
}

int fact(int a){
	if (a==1) return 1;
	return a * fact(a-1);
}

int ifact(int a){
	int fact = 1;
	for (int i =a; i>1;i--){
		fact *= i;
	}
	return fact;
}

int power(int a, int b){
	int pow = 1;
	for (int i=0; i<b;i++){
		pow *= a;
	}
	return pow;
}

int iter_coef_binom(int p, int n){
	return fact(n) / (fact(p) * fact(n-p));
}

int newt_binom(int x, int y, int n){
	return power(x+y,n);
}


int main(){
	int x,y,z;
	do{
		printf("enter x y z : ");
		scanf("%d %d %d",&x,&y,&z);
	}while (z<=0);

	printf("(%d + %d)^%d = %d",
			x,y,z,
			newt_binom(x,y,z)
	);
	return EXIT_SUCCESS;
}
