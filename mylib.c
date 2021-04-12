#include "mylib.h"

int number_res_file=0;//кількість запусків гри;
int score=0;//поточна кількість очок;


void func(){
	srand(time(0));
	int work_matr[4][4]={},fixed_matr[4][4]={}, *arr_of_empty_cells, *arr_of_ind, **changed_arr1, **changed_arr2;
	int i,j,num_of_empty_cells,selected_empty_cell;
	int firststart=1, flagmove=0, flagno=0, size;
	char name[20], keyf;
	int tempscore, record=0;
	FILE *f,*fk;
	score=0;
	changed_arr1=(int**)work_matr;
	f=fopen("res.txt","r");
	fscanf(f, "%s %d",name, &record);//зчитуємо рекорд для відображення;
	puts("Your name: ");//ввод імені гравця;
	scanf("%s",&name);	
	
	while(1){
	system("cls");
	printf("\nPRESS KEYS");
	printf("\n---------------------------------");

	printf("\nUP - 8, DOWN - 2, LEFT - 4, RIGHT - 6");
	printf("\n");
	printf("\n---------------------------------");
	printf("\nHIGHEST SCORE: %7d",record);//вивід максимального результату за всі ігри;
	printf("\nSCORE: %7d",score);
	printf("\n");
	printf("\n---------------------------------");
	printf("\n");
	arr_of_empty_cells=find_empty_cell(work_matr);
	if(arr_of_empty_cells==NULL || changed_arr1==NULL){//умова завершення гри (нема вільних комірок або достроково натиснута клавіша ESC);
	printf("\n..................................");
	printf("\n");
	printf("\n..................................");
	printf("\n");
	printf("\n------------GAME OVER------------");
	printf("\n");
	printf("\n..................................");
	printf("\n");
	printf("\n..................................");
	printf("\n");
	printf("\n..................................");

	break;
	}
	num_of_empty_cells=_msize(arr_of_empty_cells)/sizeof(int)-1;
	
	selected_empty_cell=select_one_of_empty_cells(arr_of_empty_cells, &num_of_empty_cells);
	free(arr_of_empty_cells);
	printf("\n");
	arr_of_ind=get_index_from_number(&selected_empty_cell);
	i=arr_of_ind[0];
	j=arr_of_ind[1];
	if(firststart==1)flagmove=1;
	firststart=0;
	if(flagmove==1){
		changed_arr1=input_2_or_4(work_matr, &i, &j);//якщо відбувся рух закидаємо число у вільну комірку;
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
		fixed_matr[i][j]=work_matr[i][j];//фіксуємо матрицю, щоб надалі порівняти чи відбувся рух;	
		}
			
	}	
	flagmove=0;
	printf("\n---------------------------------");
	printf("\n");
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(work_matr[i][j]==0){
			printf("|       ");
			}else printf("|%4d   ",work_matr[i][j]);//вивід матриці;
			
		}
		printf("|");
		printf("\n|       |       |       |       |");
		printf("\n---------------------------------");
		printf("\n");
	}
	cursorOff();		
	printf("\n");
	do{
	keyf=getkey();		
	}while(keyf!=52 && keyf!=54 && keyf!=56 && keyf!=50 && keyf!=27);
		if(keyf==52){
		changed_arr1=key_4(work_matr);//обробка клавіші 4;
	}
		if(keyf==54){
		changed_arr1=key_6(work_matr);//обробка клавіш 6;
	}
		if(keyf==56){
		changed_arr1=key_8(work_matr);//обробка клавіш 8;
	}
		if(keyf==50){
		changed_arr1=key_2(work_matr);//обробка клавіш 2;
	}
	if(keyf==27){
		changed_arr1=NULL;//обробка клавіші еск;
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(fixed_matr[i][j]!=work_matr[i][j]) flagmove=1;//якщо хоча б одне значення після натискання клавіші змістилось, спрацьовує флаг на рух;
		
		}

	}

}		
	fk = fopen("zapis.txt","r");//читання, обробка, запис результатів;
    if(fk==NULL){
    fk = fopen("zapis.txt","w");	
	}  	
  	fscanf(fk,"%i",&number_res_file);
  	
  	number_res_file++;
  	fclose(fk);  	
  	
	if (( f = fopen("res.txt", "a")) == NULL){
    	fprintf(stderr, "Невдається відкрити для запису файл 'res.txt'\n");
    }
	   	fprintf(f,"%s\n%i\n",name,score);
		fclose(f);
			
	res Res=(res)calloc(number_res_file,sizeof(struct Results));
	
	if (( f = fopen("res.txt", "r")) == NULL){
    	fprintf(stderr, "Невдається відкрити для запису файл 'res.txt'\n");
    	
  	}
	for(i=0;i<number_res_file;i++){
		fscanf(f, "%s %i ", Res[i].player,&Res[i].highscore);
	}

	if(number_res_file>1){
	for(j=0;j<number_res_file-1;j++){

	  	for(i=0;i<number_res_file-1-j;i++){
	  
	     	if(Res[i].highscore<Res[i+1].highscore){
	     		
	     		tempscore=Res[i].highscore;
	     		Res[i].highscore=Res[i+1].highscore;
	     		Res[i+1].highscore=tempscore;
	     		strcpy(name,Res[i].player);
	     		strcpy(Res[i].player,Res[i+1].player);
	     		strcpy(Res[i+1].player,name);
	     
	     	}	
	 	}
	}
}
	f=fopen("res.txt","w");
	
	for(i=0;i<number_res_file;i++){
		fprintf(f,"%s %d ",Res[i].player,Res[i].highscore);
	}
	fclose(f);

	if (( fk = fopen("zapis.txt","w")) == NULL){
    	fprintf(stderr, "Невдається відкрити для запису файл zapis.txt'\n");
    	
  	}
	fprintf(fk,"%i",number_res_file);
	free(Res);
	fclose(fk);	
		
}
int Menu(){
  int c = -1;
  char ch=0;
while (c<1||c>3){
  	printf("\nPress 1 to start game\n"  
		   "Press 2 to see results\n"
		   "Press 3 to read rules\n"
		   "Press ESC to exit\n"
			);
         	  ch=getch();
         	  c=ch-'0';
         	  if(c==-21){
         	  	return 0;
			   }
    }
  			return c;
}
void result()
{
	FILE *f,*fk;
	int i;
	fk = fopen("zapis.txt","r");
    fscanf(fk,"%i",&number_res_file);
  	fclose(fk); 
	printf("\n++++++++++++TABLE Records+++++++++++++\n\n");
	printf("\n        Player    -    Score");
	printf("\n......................................\n");
	res Res=(res)calloc(number_res_file,sizeof(struct Results));
	f = fopen("res.txt","r");
	for(i=0;i<number_res_file;i++){
		fscanf(f,"%s%d",Res[i].player,&Res[i].highscore);
		printf("%i. %12s    -    %12i\n",i+1,Res[i].player,Res[i].highscore);

	}
	fclose(f);
    free(Res);
}
void rules()
{
	printf("\n2048 is a game where you combine numbered tiles in order to gain a higher numbered tile.\n"
	 "\nIn this game you start with two tiles, the lowest possible number available is two.\n" 
	 "\nThen you will play by combining the tiles with the same number to have a tile with the \n"
	 "\nsum of the number on the two tiles. \n"

"\nThe game of 2048 does not include complicated controls. The controls you’ll be using are just upward(8),\n" 
"\ndownward(2), and sideways(4 and 6). The rules are also simple. You just need to move the tiles and every time you \n"
"\nmove one, another tile pops up in a random manner anywhere in the box. When two tiles with the same \n"
"\nnumber on them collide with one another as you move them, they will merge into one tile with the sum \n"
"\nof the numbers written on them initially."
	);	
}

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
int* get_index_from_number(int* selected_empty_cell)
{
	int* arr_ind;
	arr_ind=(int*)calloc(2,sizeof(int));
	
	arr_ind[0]=(*selected_empty_cell-1)/4;
	arr_ind[1]=(*selected_empty_cell-1)%4;
		
	return arr_ind;
	free(arr_ind);
}
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
char getkey()
{
	char key;
	key=getch();		
		
	return key;
}

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
int** key_2(int arr[][4]){
	int i, j, k, p, row, column, fixed_i_zero_cell, fixed_j_zero_cell, fixed_i_for_sum, fixed_j_for_sum, **ps;
	char keyf;
	ps=(int**)arr;
	for(column=3;column>=0;column--){
				for(row=3;row>=0;row--){
				if(arr[row][column]==0){
				fixed_i_zero_cell=row;
				fixed_j_zero_cell=column;
				for(i=3;i>=0;i--){
					if(arr[i][fixed_j_zero_cell]!=0 && i<fixed_i_zero_cell){

						arr[fixed_i_zero_cell][fixed_j_zero_cell]=arr[i][fixed_j_zero_cell];
						arr[i][fixed_j_zero_cell]=0;
						
						break;
					}
				}
			}	
				
		}
	}
				for(j=3;j>=0;j--){
					for(i=3;i>=0;i--){
						if(arr[i][j]==0){
							for(p=i;p>0;p--){
							arr[p][j]=arr[p-1][j];	
							arr[p-1][j]=0;	
							}
							}
						fixed_i_for_sum=i;
						fixed_j_for_sum=j;
						for(k=3;k>=0;k--){
							if(arr[fixed_i_for_sum][fixed_j_for_sum]==arr[k][fixed_j_for_sum] && fixed_i_for_sum-k==1){
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
int** key_4(int arr[][4]){
int i, j, k, p, row, column, fixed_i_zero_cell, fixed_j_zero_cell, fixed_i_for_sum, fixed_j_for_sum, **ps;
	char keyf;
	ps=(int**)arr;
	for(row=0;row<4;row++){
				for(column=0;column<4;column++){
					if(arr[row][column]==0){
					fixed_i_zero_cell=row;
					fixed_j_zero_cell=column;
					for(i=0;i<4;i++){
						if(arr[fixed_i_zero_cell][i]!=0 && i>fixed_j_zero_cell){

						arr[fixed_i_zero_cell][fixed_j_zero_cell]=arr[fixed_i_zero_cell][i];
						arr[fixed_i_zero_cell][i]=0;
						
						break;
						
					}
				}
			}	
				
		}
	}
				for(i=0;i<=3;i++){
					for(j=0;j<=3;j++){
						if(arr[i][j]==0){
							for(p=j;p<3;p++){
							arr[i][p]=arr[i][p+1];	
							arr[i][p+1]=0;	
							}
							}
						fixed_i_for_sum=i;
						fixed_j_for_sum=j;
						for(k=0;k<=3;k++){
							if(arr[fixed_i_for_sum][fixed_j_for_sum]==arr[fixed_i_for_sum][k] && k-fixed_j_for_sum==1){
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

void cursorOff(){
  
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO structCursorInfo;
GetConsoleCursorInfo(handle,&structCursorInfo);
structCursorInfo.bVisible = FALSE;
SetConsoleCursorInfo( handle, &structCursorInfo );
}
	


