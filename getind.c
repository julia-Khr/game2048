#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string.h>
int* get_index_from_number(int* selected_empty_cell)
{
	int* arr_ind;
	arr_ind=(int*)calloc(2,sizeof(int));
	
	arr_ind[0]=(*selected_empty_cell-1)/4;
	arr_ind[1]=(*selected_empty_cell-1)%4;
		
	return arr_ind;
	free(arr_ind);
}
