#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define N 16
int number_res_file=0;//кількість запусків гри;
int score=0;//поточна кількість очок;
#include "cursor.c"
#include "findempty.c"
#include "select.c"
#include "getind.c"
#include "input24.c"
#include "inpkey.c"
#include "key8.c"
#include "key2.c"
#include "key6.c"
#include "key4.c"
#include "ruls.c"
#include "menu.c"

typedef struct Results{
		char player[20];
		int highscore;
}*res;
#include "res.c"
#include "func.c"
void cursorOff();
int* find_empty_cell(int arr[][4]);//пошук вільних комірок (значення від 1 до 16);
int select_one_of_empty_cells(int* arr_of_empty_cells, int* num_of_empty_cells);//рандомний вибір однієї комірки для закидання числа;
int* get_index_from_number(int* selected_empty_cell);//повертає індекси комірки;
int** input_2_or_4(int arr[][4], int* i, int*j);//у вільну комірку закидається 2 або 4;
int getkey();
int** key_8(int arr[][4]);
int** key_2(int arr[][4]);
int** key_6(int arr[][4]);
int** key_4(int arr[][4]); 
void func();//основна функція, де викликаються інші;
int Menu();
void result();//вивід таблиці рекордів;
void rules();//правила гри;

int main()
{
	int choice;
	
	while ((choice = Menu())!=0 && choice!=-21){
		system("cls");
		switch (choice)
		{
      case 1:
        func();
        break;
      case 2:
      	result();
		break;
	  case 3:
      	rules();
		break;
	  		
		}
	
	}  
	return 0;
}


