#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define N 16

typedef struct Results{
		char player[20];
		int highscore;
}*res;


void cursorOff();
int* find_empty_cell(int arr[][4]);//����� ������ ������ (�������� �� 1 �� 16);
int select_one_of_empty_cells(int* arr_of_empty_cells, int* num_of_empty_cells);//��������� ���� ���� ������ ��� ��������� �����;
int* get_index_from_number(int* selected_empty_cell);//������� ������� ������;
int** input_2_or_4(int arr[][4], int* i, int*j);//� ����� ������ ���������� 2 ��� 4;
char getkey();
int** key_8(int arr[][4]);
int** key_2(int arr[][4]);
int** key_6(int arr[][4]);
int** key_4(int arr[][4]); 
void func();//������� �������, �� ������������ ����;
int Menu();
void result();//���� ������� �������;
void rules();//������� ���;
