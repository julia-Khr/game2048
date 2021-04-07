#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string.h>

char getkey()
{
	char key;
	int c;
	key=getch();		
	c=key-'0';	
	return c;
}
