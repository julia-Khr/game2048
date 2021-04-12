#include <stdio.h>
#include "mylib.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int choice;
	while ((choice = Menu())!=0 && choice!=27){
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
