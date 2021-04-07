#include <conio.h>
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
