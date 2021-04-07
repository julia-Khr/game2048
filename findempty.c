#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string.h>
int* find_empty_cell(int arr[][4])
{	
	int *empty_cells;
	int i, j, k=0;
	empty_cells=(int*)calloc(1,sizeof(int));
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if (arr[i][j]==0){
				empty_cells[k]=i*4+j+1;
				k++;
				empty_cells=(int*)realloc(empty_cells,(k+1)*sizeof(int));	
			}
			if(k==0)return NULL;
			return empty_cells;
	
}
