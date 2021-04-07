#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string.h>
void cursorOff(){
  
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO structCursorInfo;
GetConsoleCursorInfo(handle,&structCursorInfo);
structCursorInfo.bVisible = FALSE;
SetConsoleCursorInfo( handle, &structCursorInfo );
}

