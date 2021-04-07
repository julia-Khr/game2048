#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string.h>
int select_one_of_empty_cells(int* arr_of_empty_cells, int* num_of_empty_cells)
{
	int cell, i, flag=0;
	while(1){
	cell=1+rand()%16;
	for(i=0;i<*num_of_empty_cells;i++){
		if(arr_of_empty_cells[i]==cell){
		flag=1; 
		break;	
		}	
	}
	if(flag==1)break;
	}
		
	return cell;
}
