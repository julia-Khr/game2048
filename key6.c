#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string.h>

int** key_6(int arr[][4]){
	int i, j, k, p, row, column, fixed_i_zero_cell, fixed_j_zero_cell, fixed_i_for_sum, fixed_j_for_sum, **ps;
	char keyf;
	ps=(int**)arr;
		for(row=3;row>=0;row--){
			for(column=3;column>=0;column--){
				if(arr[row][column]==0){
				fixed_i_zero_cell=row;
				fixed_j_zero_cell=column;
					for(i=3;i>=0;i--){
						if(arr[fixed_i_zero_cell][i]!=0 && i<fixed_j_zero_cell){

						arr[fixed_i_zero_cell][fixed_j_zero_cell]=arr[fixed_i_zero_cell][i];
						arr[fixed_i_zero_cell][i]=0;
						
						break;
						
					}
				}
			}	
		}
	}
			for(i=3;i>=0;i--){
				for(j=3;j>=0;j--){
				if(arr[i][j]==0){
					for(p=j;p>0;p--){
					arr[i][p]=arr[i][p-1];	
						arr[i][p-1]=0;	
					}
				}
					fixed_i_for_sum=i;
					fixed_j_for_sum=j;
					for(k=3;k>=0;k--){
						if(arr[fixed_i_for_sum][fixed_j_for_sum]==arr[fixed_i_for_sum][k] && fixed_j_for_sum-k==1){
						arr[fixed_i_for_sum][fixed_j_for_sum]+=arr[fixed_i_for_sum][k];
						score+=arr[fixed_i_for_sum][fixed_j_for_sum];
						arr[fixed_i_for_sum][k]=0;
				
						break;
					}
				}
			}	
		}
		return ps;
}
