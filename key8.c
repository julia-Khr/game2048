#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string.h>

int** key_8(int arr[][4]){
	int i, j, k, p, row, column, fixed_i_zero_cell, fixed_j_zero_cell, fixed_i_for_sum, fixed_j_for_sum, **ps;
	char keyf;
	ps=(int**)arr;
	for(column=0;column<=3;column++){
				for(row=0;row<=3;row++){
				if(arr[row][column]==0){
				fixed_i_zero_cell=row;
				fixed_j_zero_cell=column;
				for(i=0;i<4;i++){
					if(arr[i][fixed_j_zero_cell]!=0 && i>fixed_i_zero_cell){

						arr[fixed_i_zero_cell][fixed_j_zero_cell]=arr[i][fixed_j_zero_cell];
						arr[i][fixed_j_zero_cell]=0;
						
						break;
						
					}
				}
			}	
				
		}
	}
				for(j=0;j<=3;j++){
					for(i=0;i<=3;i++){
						if(arr[i][j]==0){
							for(p=i;p<3;p++){
							arr[p][j]=arr[p+1][j];	
							arr[p+1][j]=0;	
							}
						}
						fixed_i_for_sum=i;
						fixed_j_for_sum=j;
						for(k=0;k<=3;k++){
							if(arr[fixed_i_for_sum][fixed_j_for_sum]==arr[k][fixed_j_for_sum] && k-fixed_i_for_sum==1){
							arr[fixed_i_for_sum][fixed_j_for_sum]+=arr[k][fixed_j_for_sum];
							score+=arr[fixed_i_for_sum][fixed_j_for_sum];
							arr[k][fixed_j_for_sum]=0;
							break;
						}
					}
				}	
			}
			return ps;
}
