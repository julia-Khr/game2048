#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define N 16
void func(){
	srand(time(0));
	int work_matr[4][4]={},fixed_matr[4][4]={}, *arr_of_empty_cells, *arr_of_ind, **changed_arr1, **changed_arr2;
	int i,j,num_of_empty_cells,selected_empty_cell, keyf;
	int firststart=1, flagmove=0, flagno=0, size;
	char name[20] ;
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
	}while(keyf!=2 && keyf!=4 && keyf!=6 && keyf!=8 && keyf!=-21);
		if(keyf==4){
		changed_arr1=key_4(work_matr);//обробка клавіші 4;
	}
		if(keyf==6){
		changed_arr1=key_6(work_matr);//обробка клавіш 6;
	}
		if(keyf==8){
		changed_arr1=key_8(work_matr);//обробка клавіш 8;
	}
		if(keyf==2){
		changed_arr1=key_2(work_matr);//обробка клавіш 2;
	}
	if(keyf==-21){
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

