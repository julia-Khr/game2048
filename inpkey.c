#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

int getkey()
{
	char key=0;
	int c=-1;
	key=getch();		
	c=key-'0';
	printf("\n%d",c);
	return c;
}
