#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string.h>
int** input_2_or_4(int arr[][4], int* i, int*j)
{
	int chance, **p;
	p=(int**)arr;
	chance=1+rand()%100;	
	if(chance>10){
		arr[*i][*j]=2;	
	}else arr[*i][*j]=4;  
	
	return p;
}
