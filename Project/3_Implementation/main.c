#include "header.h"

void main()
{
 int c, emp;
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
  printf("\n\t4. DELETE\n\t5. UPDATE);
  printf("\n\t6. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   break;
  case 2:
   emp = empty();
   if (emp == 0)
    printf("\nThe file is EMPTY\n");
   else
    disp();
   break;
  case 3:
   search();
   break;
  case 4:
   deletefile();
   break;
  case 5:
   update();
   break;
  case 6:
   exit(1);
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 7);
}

